#include <cstdio>
#include <algorithm>

using namespace std;

// Linked List Sorting 给链表排序

const int MAX_SIZE = 100010;
// Step 1: 创建静态链表
// 定义一个静态链表
struct Node {
    // 当前元素的指针域
    int address;
    // 数据域
    int data;
    // 指针域
    int next;
    // 结点是否在链表上
    bool flag;
} node[MAX_SIZE];

// 将有效结点全部排在数组左边
bool cmp(Node a, Node b) {
    // 当有一个为flag为false时，存在无效结点，从大到小排序
    if (!a.flag || !b.flag) {
        return a.flag > b.flag;
    } else {
        // 都为有效结点，从小到大排序
        return a.data < b.data;
    }
}

int main() {
    // Step2: 初始化链表
    // 初始化链表
    for (int i = 0; i < MAX_SIZE; i++) {
        // 默认标识为无效结点
        node[i].flag = false;
    }
    // s1 为链表的首地址，n为链表结点的总数
    int s1, n;
    scanf("%d %d", &n, &s1);
    int address, key , next;
    // 生成链表
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &address, &key, &next);
        node[address].address = address;
        node[address].data = key;
        node[address].next = next;
    }
    // 记录有效结点的数量
    int count = 0;
    // Step3: 枚举以s1为首结点地址的链表，并记录有效结点
    for (int p = s1; p != -1; p = node[p].next) {
        // 以此过滤掉无效结点
        node[p].flag = true;
        count++;
    }
    // 无有效结点
    if (count == 0) {
        printf("0 -1\n");
    } else {
        // Step4: 筛选有效结点，并进行排序
        sort(node, node + MAX_SIZE, cmp);
        // Step5: 遍历链表输出
        // 先输出有效结点总数和首结点地址
        printf("%d %05d\n", count, node[0].address);
        for (int i = 0; i < count; i++) {
            if (i < count - 1) {
                // node[i + 1].address 在不修改node[i].next的情况下，巧妙的获取了在排序后下一个结点的地址
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
            } else {
                printf("%05d %d -1\n", node[i].address, node[i].data);
            }
        }
    }
}