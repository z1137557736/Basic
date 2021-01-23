#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

/**
 * Emergency（紧急事件）图论题，求最短路径的数量(基于无向图)
 * 题意：求C1到C2最短路径的数量(最短路径可能有多个)，以及在最短路径中召集的一个最大团队数量
 */

const int MAX_SIZE = 510;
const int INF = 0x3fffffff;

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

// 起点到各点的最短距离 / 起点到各点的累加的救援团队 / 起点到各点的最短路径的数量
int d[MAX_SIZE] = {}, W[MAX_SIZE] = {}, num[MAX_SIZE] = {};
// 记录前驱结点(方便对最短路径的记录)
set<int> pre[MAX_SIZE];
// 顶点的点权
int Weight[MAX_SIZE] = {};
// 记录顶点是否入队
bool inq[MAX_SIZE] = {false};

// 顶点数量 / 边的数量 / 起点城市 / 终点城市
int n, M, C1, C2;

/**
 * BF算法与迪杰斯特拉算法不同，每个点会被访问多次
 * @param s
 */
void SPFA(int s) {
    fill(d, d + MAX_SIZE, INF);
    queue<int> q;
    q.push(s);
    // 起点的参数初始化
    d[s] = 0;
    W[s] = Weight[s];
    num[s] = 1;
    inq[s] = true;
    while (!q.empty()) {
        // 先取顶点u
        int u = q.front();
        q.pop();
        // 顶点u可重复入队
        inq[u] = false;
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v,
                dis = Adj[u][j].dis;
            if (d[u] + dis < d[v]) {    // 中介点u可以使d[v]最优
                d[v] = d[u] + dis;
                W[v] = W[u] + Weight[v];
                num[v] = num[u];
                pre[v].clear();
                pre[v].insert(u);
                // d[v]发生了改变，从顶点v发出的邻接边的边权都需要重新计算
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            } else if (d[u] + dis == d[v]) {
                if (W[u] + Weight[v] > W[v]) {
                    W[v] = W[u] + Weight[v];
                }
                pre[v].insert(u);
                num[v] = 0;
                // 重新累加前驱结点的最短路径数量
                for (auto it = pre[v].begin(); it != pre[v].end(); it++) {
                    num[v] += num[*it];
                }
                // 顶点v处的第二标尺值发生了改变，从顶点v发出的邻接边的边权都需要重新计算
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
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
    SPFA(C1);
    printf("%d %d\n", num[C2], W[C2]);
    return 0;
}