#include <cstdio>
#include <vector>

using namespace std;

/**
 * Bellman-Ford algorithm（注意：此算法支持负权边，但绝不允许有负权环）
 * 当有负边权时，使用dijkstra算法无法得到正确的最短路径，为了更好的求有负边权的图的最短路径问题，需要使用Bellman-Ford算法(简称BF算法)
 */

struct Node {
    // 顶点 / 边权
    int v, dis;
    Node(int v, int dis) {
        this -> v = v;
        this -> dis = dis;
    }
};

const int MAX_SIZE = 1000;
const int INF = 1000000000; // 无穷大

// 基于邻接矩阵
vector<Node> Adj[MAX_SIZE];
// 顶点数
int n;
// 起点到其它顶点的距离
int d[MAX_SIZE];

bool Bellman(int s) {
    // 填充默认值
    fill(d, d + MAX_SIZE, INF);
    d[s] = 0;
    // 循环对相邻结点的访问，且最短路径长度最长不会超过(|V| - 1)(可以想象，在一条链表中，总边数 = 总结点数 - 1)
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            // 遍历顶点u可达的顶点
            for (int j = 0; j < Adj[u].size(); j++) {
                int v = Adj[u][j].v,    // 邻接边的顶点
                    dis = Adj[u][j].dis;    // 邻接边的边权
                if (d[u] + dis < d[v]) {    // 以u为中介点可以使d[v]更小
                    d[v] = d[u] + dis;  // 松弛操作
                }
            }
        }
    }
    // 判断路径是否存在负环(如果有负环，会影响最短路径求解)
    for (int u = 0; u < n; u++) {
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v,    // 邻接边的顶点
                dis = Adj[u][j].dis;    // 邻接边的边权
            if (d[u] + dis < d[v]) {    // 因为负权环可以无限制的降低总距离，所以如果发现第n次操作仍可松弛，就一定存在负权环。
                // 图中存在从起点可到的负权环
                return false;
            }
        }
    }
    // 数组d的已为最优
    return true;
}

int main() {
    n = 4;
    Adj[0].push_back(Node(1, 1));
    Adj[1].push_back(Node(2, 3));
    Adj[2].push_back(Node(3, -6));
    Adj[3].push_back(Node(1, 1));
    bool flag = Bellman(0);
    if (flag) {
        printf("success");
    } else {
        printf("error");
    }
}