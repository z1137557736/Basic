#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * MST(Minimum Spanning Tree)最小生成树是在一个给定的无向图G(V, E)中求一棵树T，使得这棵树拥有图G中所有的顶点，且所有边都来自图G的边，并且满足整棵树的边权之和最小。
 * 1. 最小生成树是树，因从其边数等于顶点数减一，且树内一定不会有环
 * 2. 对于给定的图G(V, E)，其最小生成树不唯一，但其边权和一定是唯一的
 * 3. 由于最小生成树是在无向图上生成的，因此其根结点可以是这棵树上的任意一个结点
 * 求解最小生成树一般有两种算法，即prim算法以及kruskal算法。两者都采用了贪心法的思路，只是贪心的策略不同
 *
 * Prim算法(普里姆算法)的时间复杂度为O(V^2)，所以在顶点数较少，边数较多的情况下使用。
 */

const int MAX_SIZE = 1000;  // 最大顶点数
const int INF = 0x3fffffff; // 无穷大

struct Node {
    // 顶点 / 边权
    int v, dis;
    Node(int v, int dis) {
        this -> v = v;
        this -> dis = dis;
    }
};

int G[MAX_SIZE][MAX_SIZE] = {}; // 定义邻接矩阵
vector<Node> Adj[MAX_SIZE] = {}; // 定义邻接表
int n;  // 顶点数量
int d[MAX_SIZE];    // 与Dijkstra算法不同，这里记录的是各个顶点与巨型防护罩的距离
// 标识顶点是否被访问
bool vis[MAX_SIZE] = {};

int Prim(int s) {
    // 最小生成树的最短边权之和
    int ans = 0;
    // 冻结所有边
    fill(d, d + MAX_SIZE, INF);
    // 标识根结点
    d[s] = 0;
    // 每次占据一个顶点，所有n个顶点遍历n次
    for (int i = 0; i < n; i++) {
        // 以u为最优中介点
        int u = -1,
            MIN = INF;
        for (int j = 0; j < n; j++) {
            // 未被访问过的 && 距离集合S最短路径的顶点
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        // 找不到小于INF的顶点u，表示从起点S出发无法遍历图的集合V
        if (u == -1) return -1;
        ans += d[u];    // 累加距离集合S距离最小的边权
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            // 巨型防护罩以u为中介点使得d[v]的距离最优
            if (!vis[v] && G[u][v] < d[v]) {
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}

// 基于邻接表实现的Prim算法
int Prim2(int s) {
    // 最小生成树的边权之和
    int ans = 0;
    // 冻结所有边
    fill(d, d + MAX_SIZE, INF);
    // 从起点开始
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1,
            MIN = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        // 找不到小于INF的顶点u，表示从起点S出发无法遍历图的集合V
        if (u == -1) return -1;
        ans += d[u];    // 累加距离集合S距离最小的边权
        vis[u] = true;
        // 遍历邻接矩阵
        for (int j = 0; j < Adj[u].size(); j++) {
            // 巨型防护罩以u为中介点使得d[v]的距离最优
            int v = Adj[u][j].v,
                dis = Adj[u][j].dis;
            if (!vis[v] && dis < d[v]) {
                d[v] = dis;
            }
        }
    }
    return ans;
}

int main() {
    int m, s;
    fill(G[0], G[0] + MAX_SIZE * MAX_SIZE, INF);
    scanf("%d%d%d", &n, &m, &s);    // 顶点数、边数、起点编号
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);    // 输入顶点u -> 顶点v的边权v
        G[u][v] = w;
        G[v][u] = w;
        Adj[u].emplace_back(v, w);
        Adj[v].emplace_back(u, w);
    }
    // 调用prim算法
    printf("%d\n", Prim2(s));
}