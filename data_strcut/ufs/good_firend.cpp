#include <cstdio>

/**
 * 题意：好朋友，将好朋友各个分组，确保每组的任意两个数码宝贝都是好朋友，且任意两组数码宝贝之间都不是好朋友
 */
const int MAX_SIZE = 105;

int father[MAX_SIZE];
bool isRoot[MAX_SIZE] = {false};

int n   // 数码宝贝的个数 (编号为1~n)
    , m;    // 好朋友的组数

// 初始化数码宝贝
void init() {
    for (int i = 0; i <= n; i++) {
        father[i] = i;
    }
}

// 寻找根结点
int findFather(int x) {
    // 找到根结点，直接返回
    if (father[x] == x) {
        return x;
    } else {
        // 按照从根结点到x的顺序，将途经过的x的父结点都设置为根结点
        int f = findFather(father[x]);
        father[x] = f;
        // 返回根结点
        return f;
    }
}

// 合并：将a元素和b元素各自所在的集合合并为一个集合
void unionSet(int a, int b) {
    a = findFather(a);
    b = findFather(b);
    if (a != b) {
        // 将a的父结点设置为b
        father[a] = b;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    // 初始化集合
    init();
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        // 合并集合
        unionSet(a, b);
    }
    // 将根结点在isRoot设置为true
    for (int i = 1; i <= n; i++) {
        isRoot[findFather(father[i])] = true;
    }
    // 寻找集合的组数
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += isRoot[i];
    }
    printf("%d\n", ans);
}