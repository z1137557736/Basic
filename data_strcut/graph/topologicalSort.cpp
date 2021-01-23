#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

/**
 * 有向无环图：如果一个有向图的任意顶点都无法通过一些有向边回到自身，那么称这个图为有向无环图(Directed Acyclic Graph, DAG)
 * 拓扑排序是将有向无环图G的所有顶点排成一个线性序列，使得对图G中的任意两个点u、v，如果存在u -> v，那么在序列中u一定在v前面。这个序列被称为拓扑排序。
 * 使用：一般可利用拓扑排序来判断一个图是否存在环
 * 操作步骤：
 * 1. 定义一个队列Q，将所有入度为0的结点入队(显然，开始时入度为0的必为根结点)
 * 2. 取出队首结点，输出，并将该顶点可达的边的度减一，若在此过程中有存在入度为0结点，就将此结点入队
 * 3. 重复步骤2，直到队列为空。如果队列入过队的结点数量正好等于N，那么拓扑排序成功，此图G为无环图，反之，此图G为有环图
 */

const int MAX_SIZE = 1000;
// 邻接表
vector<int> Adj[MAX_SIZE];
// 顶点数 / 顶点的入度
int n, inDegree[MAX_SIZE];

// 拓扑排序
bool topologicalSort() {
    int num = 0;
    queue<int> q;
    // 将入度为0的加入队列
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        // 取出队首元素
        int u = q.front();
        q.pop();
        // 取出u的邻接边v
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j];  // 顶点v
            inDegree[v]--;  // 顶点v的入度减一
            // 当顶点v入度为0
            if (inDegree[v] == 0) {
                // 入队
                q.push(v);
            }
        }
        // 顶点入队的数量
        num++;
    }
    // 为true是拓扑排序，显然，有环图的num总是小于n（其环中的顶点的入度总是大于等于1，所有环中的顶点始终无法入队）
    return num == n;
}

int main() {

}