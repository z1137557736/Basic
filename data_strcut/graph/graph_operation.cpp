#include <cstdio>

/**
 * 图论(graph theory) 一般图会分为有向图和无向图
 * 顶点的度是指该顶点相连的边的条数，特别对于有向图，顶点的出边条数称为该顶点的出度，入边条数称为该顶点的入度
 * 存储结构有两种：邻接矩阵和邻接表
 * 邻接矩阵：基于二维数组实现，如A[i][j] = 2，表示顶点i到顶点j有边，且边权为2；当顶点超过1000时不适用，比较浪费空间
 * 邻接表：基于数组加链表实现，如A[i] = new Node(j, 3)，表示顶点i到顶点j有边，且边权为3；需要多少开多少空间（节约内存！）
 */

// 定义一个链表，也可以直接使用vector来代替实现
struct Node {
    int v   // 顶点 vertex
        , w;    // 权值
    Node* next;

    // 定义带参数构造函数
    Node(int v, int w) {
        this -> v = v;
        this -> w = w;
        this -> next = NULL;
    }
};

const int MAX_SIZE = 5;

// 定义一个存放Node指针(默认为NULL)的数组
Node* node[MAX_SIZE] = {};

// 添加i到v的一条有向边，边权为w
void insert(Node* &root, int i, int v, int w) {
    if (root == NULL) {
        root = new Node(v, w);
    } else {
        insert(root -> next, i, v, w);
    }
}

int main() {
    // 添加 一条从顶点1到顶点2的边权为4的有向边
    insert(node[1], 1, 2, 4);
    // 添加 一条从顶点1到顶点3的边权为2的有向边
    insert(node[1], 1, 3, 2);
    printf("insert success");
}