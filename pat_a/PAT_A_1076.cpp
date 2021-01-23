#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

/**
 * 题意：求微博文章的转发次数（在给定的L范围之内）
 */

struct Node {
    // 顶点编号
    int v;
    // 记录层级
    int layer;

    Node(int v, int layer) {
        this -> v = v;
        this -> layer = layer;
    }
};
const int MAX_SIZE = 1005;

// 定义邻接矩阵图（有向图）
int G[MAX_SIZE][MAX_SIZE] = {};
// n 用户数量，L 订阅用户的间接关系的层级
int n, L;

// 定义队列
queue<Node> q;
// 判断顶点是否已经入队
bool inq[MAX_SIZE] = {false};

// 广度优先搜索（方便得到遍历的层级）
int BFS(int v) {
    int ans = 0;
    Node node(v, 0);
    q.push(node);
    // 标记顶点v已入队
    inq[v] = true;
    while (!q.empty()) {
        // 取出顶点
        Node top = q.front();
        q.pop();
        // 下一层级
        int nextLayer = top.layer + 1;
        if (nextLayer <= L) {
            // 枚举user[i] ~ user[n]
            for (int i = 1; i <= n; i++) {
                // user[i] 与 user[n] 邻接(有边) && 顶点i未被访问
                if (G[top.v][i] > 0 && !inq[i]) {
                    ans++;
                    // 顶点i入队
                    Node temp(i, nextLayer);
                    // 标记顶点i已入队
                    inq[i] = true;
                    q.push(temp);
                }
            }
        }
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &L);
    int M, v, k;
    // 建立图：user[i] ~ user[n]
    for (int i = 1; i <= n; i++) {
        scanf("%d", &M);
        // 遍历user[i]订阅的用户
        for (int j = 0; j < M; j++) {
            scanf("%d", &v);
            // 因为 user[i]是订阅 user[v]，反过来，应该是user[i]转发user[v]发的文章
            // 顶点v -> 顶点i(有向边)
            G[v][i] = 1;
        }
    }
    // 查询个数
    scanf("%d", &k);
    int userId;
    // 计算user[userId]用户发文章的一个最大转发量(订阅用户(userId)的间接关系的层级 ≤ L)
    for (int i = 0; i < k; i++) {
        // 再次初始化数组
        memset(inq, false, sizeof(inq));
        scanf("%d", &userId);
        printf("%d\n", BFS(userId));
    }
}