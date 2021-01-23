#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * dijkstra algorithm（迪杰斯特拉算法）
 */
const int MAX_SIZE = 1000;
// 标识不可达的点
const int INF = 1000000000;

// 标识起点d[s]到顶点V[i]的最短路径距离，初始时起点d[s]设为0，其余顶点赋值为INF(标识为不可达)
int d[MAX_SIZE] = {};

// 记录前驱结点（利用它可以得到起点到终点的一个最短路径）
int pre[MAX_SIZE] = {};

// 标识顶点是否被访问
bool vis[MAX_SIZE] = {false};

// 基于邻接表
struct Node {
    // v 为顶点，w为边权
    int v, w;
};

// 类似(数组 + 链表)的结构
vector<Node> V[MAX_SIZE] = {};

// 基于邻接矩阵
int G[MAX_SIZE][MAX_SIZE] = {};

// n为顶点数
int n;

/**
 * 邻接矩阵版（适用于顶点数不大的情况）
 * 第一步：将地图上的边全部抹去(边权设置为INF)，并选择城市V[0]进行攻占(即设置d[0] = 0，显然V[0]到V[0]的距离为0)
 * 第二部：当攻占完这个城市时，将其可到达的边显现出来(边权也显现出来了)
 * 第三部：选择V[0]最近的城市进行攻占
 * 总结：局部最优结构来保证全局最优结构（贪心算法的思想）
 * @param s 起点
 */
void Dijkstra(int s) {
    // 起点到其它点的距离为INF
    fill(d, d + MAX_SIZE, INF);
    // 起点到自身的距离为0
    d[s] = 0;
    // 初始状态下每个点的前驱结点为自身
    /*for (int i = 0; i < n; i++) {
        pre[i] = i;
    }*/
    // 枚举每一个顶点，第一次循环会从起点d[s]开始
    for (int i = 0; i < n; i++) {
        int u = -1  // 局部最短路径的顶点
            , MIN = INF;    // 局部最短路径的长度
        for (int j = 0; j < n; j++) {
            // 未被访问的顶点 && 寻找d[u]可达顶点中边权最小的点
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        // 无可达顶点，退出循环
        if (u == -1) return;
        // 标记顶点u为已访问
        vis[u] = true;
        // 枚举顶点u可到达的顶点
        for (int v = 0; v < n; v++) {
            /**
             * d[v]用来记录：顶点s到顶点v的最短路径长度(默认为INF)
             * d[u](局部最短路径的长度) + 顶点u到顶点v的路径长度 < d[v]
             */
            if (!vis[v] && G[u][v] > 0 && d[u] + G[u][v] < d[v]) {
                // 更新d[v]为局部最短路径长度
                d[v] = d[u] + G[u][v];
                // 记录顶点v的前驱结点为u
                pre[v] = u;
            }
        }
    }
}

/**
 * 从城市s开始，攻占其它所有城市的一个最短距离
 * @param s 起点
 */
void Dijkstra2(int s) {
    // 关闭所有可达的通道
    fill(d, d + MAX_SIZE, INF);
    // 攻占起点城市
    d[s] = 0;
    // 枚举n次，因为要攻占n次城市，才能将所有城市攻占
    for (int i = 0; i < n; i++) {
        // 定义默认值
        int u = -1,
            MIN = INF;
        for (int j = 0; j < n; j++) {
            // 寻找附近最近的且未被攻占的城市
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        // 没有可攻占的城市
        if (u == -1) break;
        // 攻占城市[u]
        vis[u] = true;
        for (int v = 0; v < V[u].size(); v++) {
            int t_v = V[u][v].v,    // t_v 为城市[u]附近可攻占的城市编号
                t_w = V[u][v].w;    // t_w 为对应的距离
            // 城市[u] 为中介点，是从起点城市[s]攻占到城市[t_v]的一个最短距离（攻占最短距离）
            // 城市[t_v] 未被攻占 && 攻占最短距离 + 到城市[t_v]的距离 < 原最短距离
            if (!vis[t_v] && d[u] + t_w < d[t_v]) {
                // 更新最短距离
                d[t_v] = d[u] + t_w;
            }
        }
    }
}

/**
 * 寻找最短路径，通过递归前驱结点
 * @param s 起点
 * @param v 当前访问的顶点编号(从终点开始递归)
 */
void DFS(int s, int v) {
    if (s == v) {
        printf("%d ", s);
        return;
    }
    DFS(s, pre[v]);
    printf("%d ", v);
}

int main() {
    int m, s;
    scanf("%d%d%d", &n, &m, &s);    // 顶点数、边数、起点编号
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);    // 输入顶点u -> 顶点v的边权v
        G[u][v] = w;
        Node node;
        node.v = v;
        node.w = w;
        V[u].push_back(node);
    }
    // 调用迪杰斯特拉算法
    Dijkstra(s);
    for (int i = 0; i < n; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");
    DFS(s, n - 1);
}