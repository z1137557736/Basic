#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Travel Plan (旅游计划) 为无向图
 * 题意：给定旅游计划的起始站和终点站，求最短路径（如有距离相同的最短路径时，选择经过高速路口的cost最低的最短距离）
 * 实现算法：dijkstra算法 + DFS
 *
 * 可以发现：当存在第二标尺时，代码会逻辑会变得复杂，且易出错
 * 所以我们用迪杰斯特拉算法来记录所有的最短路径，然后在所有的最短路径中选出一条满足第二标尺最优的路径
 */

const int MAX_SIZE = 510;   // 最大顶点数
const int INF = 1000000000; // 无穷大

// 邻接矩阵
int G[MAX_SIZE][MAX_SIZE] = {};

// 顶点数 / 边的数量 / 起始站 / 终点站
int n, M, S, D;

// 标识顶点是否被访问
bool vis[MAX_SIZE] = {};
// 记录起点到其它顶点的距离
int d[MAX_SIZE] = {};
// 记录点到点的路费
int cost[MAX_SIZE][MAX_SIZE] = {};
// 记录所有的最短路径
vector<int> pre[MAX_SIZE] = {};

// 迪杰斯特拉算法
void Dijkstra() {
    // 去掉所有边
    fill(d, d + MAX_SIZE, INF);
    // 进入起始站
    d[S] = 0;
    // n个顶点就遍历n次（每次只会选择最短路径的顶点）
    for (int i = 0; i < n; i++) {
        int u = -1,
            MIN = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        // 无可达的边，退出循环
        if (u == -1) break;
        // 标识为已访问
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && G[u][v] > 0) {
                // 中介点d[u]可以使d[v]更优
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    // 覆盖原来的前驱结点
                    pre[v].clear();
                    // 记录新的前驱结点
                    pre[v].push_back(u);
                } else if (d[u] + G[u][v] == d[v]) {
                    // 多条相同路径，直接添加
                    pre[v].push_back(u);
                }
            }
        }
    }
}

// 起始站到终点站的最低成本(高速路费)
int minValue = INF;
// 最优路径 / 临时存取路径
vector<int> path, tempPath;

/**
 * DFS 遍历所有的最短路径(递归树)，再根据第二标尺挑选出最优路径
 * @param v 终点站往回搜起点站(形成了一个数的递归)
 */
void DFS(int v) {
    // 到找到起始站时，退出循环
    if (v == S) {
        // 加入临时路径
        tempPath.push_back(v);
        // 记录当前路径花费之和
        int value = 0;
        // 倒着访问（tempPath是从终点站到起始站的顺序）(注意这里是 i > 0，为i ≥ 0会下标越界)
        for (int i = tempPath.size() - 1; i > 0; i--) {
            int cur = tempPath[i], next = tempPath[i - 1];
            value += cost[cur][next];
        }
        // 由题意得到的最优结构
        if (value < minValue) {
            minValue = value;
            path = tempPath;
        }
        // 出栈
        tempPath.pop_back();
        return;
    }
    // 加入临时路径
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    // 出栈(后进先出)
    tempPath.pop_back();
}

int main() {
    scanf("%d%d%d%d", &n, &M, &S, &D);
    for (int i = 0; i < M; i++) {
        int c1, c2;
        scanf("%d%d", &c1, &c2);
        scanf("%d%d", &G[c1][c2], &cost[c1][c2]);
        G[c2][c1] = G[c1][c2];
        cost[c2][c1] = cost[c1][c2];
    }
    Dijkstra(); // 调用Dijkstra算法
    DFS(D); // 根据第二标尺计算最优路径
    // 倒序访问(从起始站到终点站)
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", d[D], minValue);
}