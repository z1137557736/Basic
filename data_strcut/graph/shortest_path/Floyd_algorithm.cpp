#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * Floyd 算法，用来解决全源最短路径的问题，即对给定的图G(V, E)，求任意两点u, v之前的最短路径长度，时间复杂度为O(n^3)
 * 由于复杂度过高，一般应用于顶点数不超200的图中，因此考虑可以使用邻接矩阵
 */

const int MAX_SIZE = 200;    // 最大顶点数
const int INF = 0x3fffffff; // 无穷大
int n;  // 顶点数
// 全源最短距离
int dis[MAX_SIZE][MAX_SIZE] = {};

// Floyd 算法
void Floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 以k为中点，暴力枚举各个顶点的最短路径距离
                if (dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main() {
    int m;
    scanf("%d%d", &n, &m);    // 顶点数、边数
    fill(dis[0], dis[0] + MAX_SIZE * MAX_SIZE, INF);
    for (int i = 0; i < n; i++) {
        dis[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);    // 输入顶点u -> 顶点v的边权v
        dis[u][v] = w;  // 基于有向图
    }
    // 调用Floyd算法
    Floyd();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
}