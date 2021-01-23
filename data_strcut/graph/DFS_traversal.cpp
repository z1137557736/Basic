#include <cstdio>
#include <vector>

using namespace std;

const int MAX_V = 1000;
const int F = 0;

// 顶点数
int n;
// 定义邻接矩阵
int G[MAX_V][MAX_V] = {};
// 定义邻接表
vector<int> G2[] = {};
// 标识顶点是否被访问
int vis[MAX_V];

/** 邻接矩阵版本 start **/

/**
 * v为顶点，若给定的图是一个连通图时，则只需要一次DFS就可完成遍历
 * 连通图：任取图G(V, E)中的两个顶点都能互相连通
 * @param v 顶点v
 */
void DFS(int v) {
    // 标识顶点v已被访问
    vis[v] = true;
    // 枚举顶点v可以到达的每一个顶点
    for (int i = 0; i < n; i++) {
        // 未被访问放过 && 顶点v到顶点i有一条有向边
        if (!vis[i] && G[v][i] != F) {
            DFS(i);
        }
    }
}

/**
 * 遍历图，如果图G不是连通图，则枚举其每个顶点
 */
void traverG() {
    // 枚举每一个未被访问过的顶点
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            DFS(i);
        }
    }
}
/** 邻接矩阵版本 end **/

/** 邻接表版本 start **/

void DFS2(int v) {
    // 标识为已访问
    vis[v] = true;
    // 枚举顶点v可以到达所有顶点
    for (int i = 0; i < G2[v].size(); i++) {
        // 可以到达的顶点
        int u = G2[v][i];
        // 顶点v到顶点i未被访问
        if (!vis[u]) {
            DFS2(u);
        }
    }
}

// 遍历图
void traverG2() {
    for (int i = 0; i < n; i++) {
        // 枚举每一个未被访问过的顶点
        if (!vis[i]) {
            DFS2(G2[i].front());
        }
    }
}

int main() {

}