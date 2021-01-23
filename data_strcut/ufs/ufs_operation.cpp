#include <cstdio>

/**
 * UFS(union find set)合并、查找、集合。一个集合只能有一个根结点，支持两个操作
 * 一：合并两个集合
 * 二：判断两个元素是否在同一个集合中
 */

const int MAX_SIZE = 7;

int father[MAX_SIZE];

// 递推寻找根结点
int findFather(int x) {
    // 设定ele为原元素x
    int ele = x;
    // 如果不是根结点，继续循环
    while (father[x] != x) {
        x = father[x];  // 将x替换其父结点
    }
    // 开始路径压缩
    // 若ele不是根结点，直接将其父结点设置为根结点
    while (father[ele] != ele) {
        int f = father[ele];    // 先记录ele元素的父结点
        father[ele] = x;    // 将ele父结点设置为根结点
        ele = f;    // ele执行其原父结点，重复执行上述操作
    }
    return x;
}

// 利用递归寻找根结点
int findFather2(int x) {
    // 找到根结点，退出循环
    if (father[x] == x) return x;
    // 将x替换其父结点，继续递归寻找
    else {
        // 开始路径压缩
        // 递归寻找父结点
        int f = findFather2(father[x]);
        // 将x的父结点设置为f
        father[x] = f;
        // 返回父结点
        return f;
    }
}

// 将两个元素所属的集合合并
void union_set(int a, int b) {
    // 寻找元素的根结点
    int faA = findFather2(a);
    int faB = findFather(b);
    // 各自的根结点不同，表明这两个元素不属于同一个集合
    if (faA != faB) {
        // 合并集合，将faB设为根结点
        father[faA] = faB;
    }
}

int main() {

    // 初始化集合 father[i] = I；i代表元素i，I代表元素i的父结点
    for (int i = 0; i < MAX_SIZE; i++) {
        father[i] = i;
    }
    /** 定义 1 2 3 4 是一个集合，1为根结点 **/
    father[1] = 1;  // 元素1是根结点
    father[2] = 1;  // 设置元素2的父结点是1
    father[3] = 2;  // 设置元素3的父结点是2
    father[4] = 3;  // 设置元素4的父结点是2
    /** 定义 5 6 是另一个集合，5为根结点 **/
    father[5] = 5;  // 元素5是根结点
    father[6] = 5;  // 元素6的父结点是5
    union_set(4, 6);
    printf("success");
}