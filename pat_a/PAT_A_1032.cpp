#include "cstdio"

// Sharing(找相同的单词后缀)

const int MAX_SIZE = 100010;

// 定义一个静态(单)链表，next为数组的下标
// 动态链表是在内存中随机分布
// 静态链表是在数组(一块连续的内存)中随机分布(当指针数较小时可以考虑使用静态链表)
struct Node {
    // 数据域
    char data;
    // 指针域
    int next;
    // 标识符：true存在，false不存在
    bool flag;

    // 初始化链表：默认构造函数flag标识为false
    Node() {
        flag = false;
    }
} node[MAX_SIZE];

int main() {
    // 起始地址1, 起始地址2, n为单词数量
    int s1, s2, n;
    scanf("%d %d %d", &s1, &s2, &n);
    // 当前地址, 下一个地址
    int address, next;
    char data;
    for (int i = 0; i < n; i++) {
        scanf("%d %c %d", &address, &data, &next);
        // 数据域赋值
        node[address].data = data;
        // 指定下一个地址
        node[address].next = next;
    }
    // 遍历第一个链表，从首地址s1开始遍历
    for (int p1 = s1; p1 != -1; p1 = node[p1].next) {
        // 标识结点为存在
        node[p1].flag = true;
    }

    int p2;
    // 遍历第二个链表，从首地址s2开始遍历
    for (p2 = s2; p2 != -1; p2 = node[p2].next) {
        // 当找到与第一个链表相同的后缀，返回其首地址，然后break退出循环
        if (node[p2].flag) break;
    }
    // 如果第二个链表的指针还没有到链尾-1，说明找到了公共结点
    if (p2 != -1) {
        // 5位数补0
        printf("%05d\n", p2);
    } else {
        printf("-1\n");
    }
}
