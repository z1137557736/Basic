#include "cstdio"
#include "stdlib.h"

struct node {   // 链表结点
    // 数据域
    int data;
    // 指针域
    node* next;
};

// 动态申请内存，返回的对象指针
// 申请内存: malloc  释放内存: free     note: #include "stdlib.h"
// 申请内存: new     释放内存: delete
int main() {
    // 使用malloc申请内存
    node* p1 = (node*) malloc(sizeof(node));
    p1 -> data = 1;
    // nullptr or NULL
    p1 -> next = nullptr;
    // 使用new申请内存
    node* p2 = new node;
    p2 -> data = 2;
    p2 -> next = p1;

    printf("%d %d %d\n", p2 -> data, p2 -> next -> data, p1 -> next);
    // 释放内存，并将其指向 NULL
    free(p1);
    delete(p2);
}