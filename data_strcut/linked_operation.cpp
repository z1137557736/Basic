#include <cstdio>

// 链表结点(带头结点)
struct node {
    // 数据域
    int data;
    // 指针域
    node* next;
};

// 创建结点链表
node* create(const int arr[]) {
    // head头结点不存值，头结点下一个结点开始存值
    node *head, *pre, *next;
    head = new node;
    // 偏移指针(保留当前指针的前驱结点)
    pre = head;
    // 带头节点链接下一个结点
    // 获取数组长度
    for (int i = 0; i< 5; i++) {
        // 创建next结点
        next = new node;
        // 赋值
        next -> data = arr[i];
        // 下一个元素为空(默认不为空)
        next -> next = nullptr;
        // 链接下一个结点
        pre -> next = next;
        // pre 指向下一个 next
        pre = next;
    }
    return head;
}

// 计算以head为头结点的链表上查询x在链表中出现的次数
int search(node *head, int x) {
    node *p = head -> next;
    int count = 0;
    while (p != nullptr) {
        if (p -> data == x) {
            count++ ;
        }
        p = p -> next;
    }
    return count;
}

// 将x插入以head为头结点的链表的第pos位置上
void insert(node *head, int pos, int x) {
    node *p = head;
    // 找到pos位置的上一个结点
    for (int i = 1; i < pos; i++) {
        // 往下一个结点找
        p = p -> next;
    }
    node *next = new node;  // 新建结点
    next -> data = x;   // 结点赋值
    next -> next = p -> next;   // 将新建结点的下一个结点指向当前pos位置的结点
    p -> next = next;   // 上一个结点指向新建结点
}

// 删除以head为头结点的链表中所以数据域为x的结点
void del(node *head, int x) {
    // 上一个结点
    node *pre = head;
    // 当前结点
    node *p = head -> next;
    while (p != nullptr) {
        // 当前结点的数据域等于x
        if (p -> data == x) {
            // 前驱结点的下一个结点指向p的下一个结点(因为当前p结点要被释放)
            pre -> next = p -> next;
            // 释放当前结点
            delete(p);
            // p为pre的下一个结点
            p = pre -> next;
        } else {
            // 当前数据域不是x, pre 和 p 都前进一位
            pre = p;
            p = p -> next;
        }
    }
}

int main() {
    int arr[5] = {1, 3, 3, 9, 7};
    node *head = create(arr);
    // 头结点
    node *next = head -> next;
    insert(head, 3, 5);
    del(head, 3);
    while (next != nullptr) {
        printf("%d ", next -> data);
        next = next -> next;
    }
    printf("\n");
    printf("%d\n", search(head, 9));
    return 0;
}