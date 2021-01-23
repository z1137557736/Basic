#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

/**
 * 采用BFS(Breadth First Search)遍历图
 */

queue<int> q;

const int MAX_SIZE = 1000;

// 定义邻接表 图
vector<int> V[MAX_SIZE] = {};

int G[MAX_SIZE][MAX_SIZE] = {}, // 定义邻接矩阵 图
    n;  // 顶点数量

// 标识当前顶点是否已入队
bool inq[MAX_SIZE] = {false};

// 邻接矩阵：遍历一个连通块
void BFS(int v) {
    inq[v] = true;
    // 顶点v已入队
    q.push(v);
    while (!q.empty()) {
        // 取出顶点
        int top = q.front();
        q.pop();
        // 枚举与顶点top邻接的顶点i
        for (int i = 0; i < n; i++) {
            // 顶点i未被访问过
            if (G[top][i] > 0 && !inq[i]) {
                // 顶点i入队
                q.push(i);
                // 提前标识为已入队，避免重复入队
                inq[i] = true;
            }
        }
    }
}

// 邻接表(数组 + 链表)：遍历一个连通块
void BFS2(int v) {
    q.push(v);
    // 顶点v已入队
    inq[v] = true;
    while (!q.empty()) {
        // 取出顶点
        int top = q.front();
        q.pop();
        // 枚举与顶点top邻接的顶点k
        for (int i = 0; i < V[top].size(); i++) {
            int k = V[top][i];
            // 未被访问过的顶点k
            if (!inq[k]) {
                // 顶点k入队
                q.push(k);
                // 提前标识为已入队，避免重复入队
                inq[k] = true;
            }
        }
    }
}

// 遍历整个图
void traverG() {
    for (int i = 0; i < n; i++) {
        // 未被访问过的顶点
        if (!inq[i]) {
            BFS(i);
        }
    }
}

int main() {

}