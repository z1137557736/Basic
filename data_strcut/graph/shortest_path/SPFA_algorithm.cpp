#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

/**
 * SPFA(Shortest Path Faster Algorithm)
 * 基于Bellman-Ford算法的一个优化；只有当顶点u的d[u]的值发生改变时，从d[u]出发的邻接边的边权也要重新计算
 * 在SPFA上还有进一步的优化，将FIFO队列替换成优先队列(priority_queue)；或替换为双端队列(deque)使用SLF(Small Label First)和LLL(Large Label Last)可以提升50%的效率
 * 如果将队列换成栈，可以实现DFS版本的SPFA，对判负环有奇效
 */

const int MAX_SIZE = 1000;  // 最大顶点数
const int INF = 0x3fffffff; // 无穷大

struct Node {
    // 顶点 / 边权
    int v, dis;
    // 构造函数
    Node(int _v, int _dis) : v(_v), dis(_dis) {};
};

// 定义邻接表
vector<Node> Adj[MAX_SIZE];
// 设置顶点数 / 顶点s到各点的距离 / 顶点u入队的次数(无可达负权环时可去掉)
int n, d[MAX_SIZE], num[MAX_SIZE] = {0};
bool inq[MAX_SIZE] = {false};

queue<int> q;

bool SPFA(int s) {
    fill(d, d + MAX_SIZE, INF);
    // 初始化起点参数
    q.push(s);
    inq[s] = true;  // 标识为已入队
    num[s]++;   // 入队次数+1
    d[s] = 0;   // 标识起点
    while (!q.empty()) {
        // 取出队首元素
        int u = q.front();
        q.pop();
        // 同一个顶点可以入队多次
        inq[u] = false;
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v,
                dis = Adj[u][j].dis;
            if (d[u] + dis < d[v]) {    // 以u为中介点保证d[v]最优
                d[v] = d[u] + dis;
                // 顶点v不在队列中
                if (!inq[v]) {
                    // d[v]的值发生改变时，从顶点v出发邻接边的边权也需要重新计算
                    q.push(v);
                    inq[v] = true;  // 顶点v标识为已入队
                    num[v]++;   // 顶点v入队次数+1
                    if (num[v] >= n) return false;  // 有可达负权环(会造成死循环)，直接退出
                }
            }
        }
    }
    // 无可达负权环
    return true;
}

int main() {
    n = 4;
    Adj[0].push_back(Node(1, 1));
    Adj[1].push_back(Node(2, 3));
    Adj[2].push_back(Node(3, -6));
    Adj[3].push_back(Node(1, 1));
    bool flag = SPFA(0);
    if (flag) {
        printf("success");
    } else {
        printf("error");
    }
    return 0;
}