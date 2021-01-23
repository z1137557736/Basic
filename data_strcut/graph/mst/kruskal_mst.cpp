#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * kruskal算法(也称为"克鲁斯卡尔算法")，其也用用来解决MST(最小生成树)的方案，与prim算法不同，kruskal算法采用了边贪心(所以它无需起点)的思路
 * 显然kruskal适用于稀疏图(边少)，而prim适用于稠密图(边多)
 */

const int MAXV = 1000;  // 最大顶点数
const int MAXE = 1000;  // 最大边数

// 边结构
struct Edge {
    int u, v;   // 边的两个端点
    int cost;   // 边权
} E[MAXE];

// 正序排序
bool cmp(Edge a, Edge b) {
    return a.cost < b.cost;
}

int Father[MAXV] = {};
// 顶点数 / 边数 / 累计边数
int n, m, sum_edge = 0;

// 递归寻找父结点
int findFather(int x) {
    if (Father[x] == x) return x;
    else {
        // 开始路径压缩
        // 递归寻找父结点
        int f = findFather(Father[x]);
        // 将途径x的父结点设置为f
        Father[x] = f;
        // 返回父结点
        return f;
    }
}

// Kruskal算法，显然sort快速排序的复杂度最高，所以时间复杂度为O(|E|log|E|)
int Kruskal() {
    // 最小生成树的边权和
    int ans = 0;
    // 初始化集合
    for (int i = 0; i < n; i++) {
        Father[i] = i;
    }
    // 快排
    sort(E, E + m, cmp);
    for (int i = 0; i < m; i++) {
        int fu = findFather(E[i].u),
            fv = findFather(E[i].v);
        // 根结点不相等时
        if (fu != fv) {
            // 合并集合
            Father[fu] = fv;
            // 累加最小生成树的边权
            ans += E[i].cost;
            sum_edge++;
            // 最小生成树已拥有图G的全部顶点
            if (sum_edge == n - 1) return ans;
        }
    }
    // 图G不是连通图，返回-1
    return -1;
}

int main() {
    scanf("%d%d", &n, &m);    // 顶点数、边数
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);    // 输入顶点u -> 顶点v的边权v
    }
    // 调用prim算法
    printf("%d\n", Kruskal());
    return 0;
}