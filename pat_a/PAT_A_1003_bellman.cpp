#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
 * Emergency（紧急事件）图论题，求最短路径的数量(基于无向图)
 * 题意：求C1到C2最短路径的数量(最短路径可能有多个)，以及在最短路径中召集的一个最大团队数量
 */

const int MAX_SIZE = 510;
const int INF = 1000000000;

struct Node {
    // 顶点 / 边权
    int v, dis;
    Node(int v, int dis) {
        this -> v = v;
        this -> dis = dis;
    }
};

// 邻接表
vector<Node> Adj[MAX_SIZE];

// 记录起点到各点的最短距离
int d[MAX_SIZE] = {};
// 记录起点到各点的累加的救援团队(emergency rescue team)
int W[MAX_SIZE] = {};
// 记录起点到各点的最短路径的数量
int num[MAX_SIZE] = {};
// 记录前驱结点(方便对最短路径的记录)
set<int> pre[MAX_SIZE];
// 顶点的点权
int Weight[MAX_SIZE] = {};

// 顶点数量 / 边的数量 / 起点城市 / 终点城市
int n, M, C1, C2;

/**
 * BF算法与迪杰斯特拉算法不同，每个点会被访问多次
 * @param s
 */
void Bellman(int s) {
    fill(d, d + MAX_SIZE, INF);
    // 从起点开始，顶点相关参数初始化
    d[s] = 0;
    W[s] = Weight[s];
    num[s] = 1;
    // 枚举每一个顶点对邻接边的访问
    for (int i = 0; i < n - 1; i++) {
        // 顶点u对邻接边的访问
        for (int u = 0; u < n; u++) {
            // 枚举顶点u的邻接边
            for (int j = 0; j < Adj[u].size(); j++) {
                int v = Adj[u][j].v,
                    dis = Adj[u][j].dis;
                if (d[u] + dis < d[v]) {    // 以u为中介点使得d[v]最优
                    // 覆盖原值
                    d[v] = d[u] + dis;
                    W[v] = W[u] + Weight[v];
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].insert(u);
                } else if (d[u] + dis == d[v]) {
                    // weight为点权(救援团队)
                    if (W[u] + Weight[v] > W[v]) {  // 以u为中介点使得W[v]点权之和最优
                        // 相同距离，但是能使召集的rescue team更多
                        W[v] = W[u] + Weight[v];
                    }
                    pre[v].insert(u);
                    // 重新计算
                    num[v] = 0;
                    // 累加前驱结点(可能有多个)的最短路径数量
                    for (auto it = pre[v].begin(); it != pre[v].end(); it++) {
                        num[v] += num[*it];
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &M, &C1, &C2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &Weight[i]);
    }
    int c1, c2, L;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &c1, &c2, &L);
        // 无向图
        Adj[c1].push_back(Node(c2, L));
        Adj[c2].push_back(Node(c1, L));
    }
    Bellman(C1);
    printf("%d %d\n", num[C2], W[C2]);
    return 0;
}