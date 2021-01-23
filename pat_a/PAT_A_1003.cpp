#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * Emergency（紧急事件）图论题，求最短路径的数量(基于无向图)
 * 题意：求C1到C2最短路径的数量(最短路径可能有多个)，以及在最短路径中召集的一个最大团队数量
 */

const int MAX_SIZE = 510;
const int INF = 10000000;

// 定义邻接矩阵
int G[MAX_SIZE][MAX_SIZE] = {};
// 标识顶点是否被访问
bool vis[MAX_SIZE] = {false};
// 记录起点到各个点的距离
int d[MAX_SIZE] = {};
// 记录顶点的权值
int V[MAX_SIZE] = {};
// 记录最短路径的数量
int num[MAX_SIZE] = {};
// 途中可召集营救团队的数量
int W[MAX_SIZE] = {};
// 顶点数量 / 边的数量 / 起点城市 / 终点城市
int n, M, C1, C2;

// 迪杰斯特拉算法
void Dijkstra() {
    // 擦除所有的边
    fill(d, d + MAX_SIZE, INF);
    // 起始位置
    d[C1] = 0;
    W[C1] = V[C1];
    num[C1] = 1;
    // 枚举n次，确保每个点都有机会被访问
    for (int i = 0; i < n; i++) {
        int u = -1,
            MIN = INF;
        for (int j = 0; j < n; j++) {
            // 寻找最近的且未被访问的顶点
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        // 附近无顶点
        if (u == -1) break;
        // 标识为已访问
        vis[u] = true;
        // 显现顶点u可到达的顶点
        for (int v = 0; v < n; v++) {
            // 寻找可达顶点，从城市u 达到 城市v
            if (!vis[v] && G[u][v] > 0) {
                // 以u为中介点可以使得d[v]更优
                if (d[u] + G[u][v] < d[v]) {
                    // 覆盖原有值
                    d[v] = d[u] + G[u][v];
                    num[v] = num[u];    // 继承前驱结点最短路径的数量
                    W[v] = W[u] + V[v];
                } else if (d[u] + G[u][v] == d[v]) {    // 第n(n >= 2)次发现相同最短路径，根据题意更新对应对应的值
                    // num[v](其它顶点到达顶点v的最短路径数量) + 前驱结点最短路径的数量
                    num[v] += num[u];
                    // 城市u的累加救援团队 + 城市v的救援团队 > 原城市v累加的救援团队
                    if (W[u] + V[v] > W[v]) {
                        // 大于则更新
                        W[v] = W[u] + V[v];
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &M, &C1, &C2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &V[i]);
    }
    int c1, c2, L;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &c1, &c2, &L);
        // 无向图
        G[c1][c2] = L;
        G[c2][c1] = L;
    }
    Dijkstra();
    printf("%d %d", num[C2], W[C2]);
}