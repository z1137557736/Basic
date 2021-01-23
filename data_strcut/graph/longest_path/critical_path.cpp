#include <cstdio>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * 顶点活动(Activity On Vertex, AOV)网是指用顶点表示活动，而用边集来表示活动间的优先关系的有向图，如先导课程示意图，顶点则为活动，有向边代表课程的先导关系。
 * 边活动(Activity On Edge, AOE)网是指带边权的边集表示活动，而用顶点来表示事件的有向图，其中边权表示完成活动需要的时间。
 * AOE网中的最长路径被称为关键路径（或者说：关键路径就是AOE网中的最长路径），而把关键路径上的活动称为关键活动，显然关键活动会影响整个工程的进度。
 * 想一想，既然关键路径的定义是AOE网中的最长路径，而其又为工程的最短完成时间呢？
 *
 * 关键路径(AOE网中的最长路径)实现方式
 * 第一种：将图G中所有边乘-1，然后再用BF算法或SPFA算法实现，其结果再取相反值即可。
 * 第二种：求解有向无环图关键路径
 * 先设置数组e[]和l[]，其中e[r]和l[r]分别表示活动a[r]的最早开始时间和最迟开始时间。（显然，关键活动的最早开始时间和最迟开始时间总是相等的，所以e[r] == l[r]是活动r为关键活动）
 * V[i] -> a[r] ->V[j]，显然顶点作为事件，可能会有拖延的可能，因此会存在最早发生时间和最迟发生时间
 * 设数组ve[]和vl[]，ve[i]和vl[i]分别为活动的最早开始时间(旧活动的最早结束时间)和最迟开始时间(新活动的最迟开始时间)
 * 判别关系：
 * 1. 对活动a[r]来说，只要在事件V[i]最早发生时开始，就可使活动a[r]的开始时间最早，因此e[r] = ve[i]
 * 2. 如果l[r]是活动a[r]的最迟发生时间，那么l[r]  == vl[j] - length[r](代表a[r]的边权)
 */

struct Node {
    // 顶点 / 边权
    int v, dis;
    // 带参数的构造函数
    Node(int _v, int _dis) : v(_v), dis(_dis){};
};

const int MAX_SIZE = 1000;
// 邻接表
vector<Node> Adj[MAX_SIZE];
// 顶点数 / 顶点的入度
int n, inDegree[MAX_SIZE];
// 活动最早开始时间 / 活动最迟开始时间
int ve[MAX_SIZE] = {}, vl[MAX_SIZE] = {};
// 逆拓扑序列
stack<int> topOrder;

// 拓扑排序，顺求ve数组
bool topologicalSort() {
    queue<int> q;
    for(int i = 0; i < n; i++) {
        // 将入度为0的点入队
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // 将顶点u入拓扑序列中
        topOrder.push(u);
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            // 顶点v的入度减一
            inDegree[v]--;
            // 将入度为0的点入队
            if (inDegree[v] == 0) {
                q.push(v);
            }
            // 以u为中介点使得ve[v]最大
            if (ve[u] + Adj[u][j].dis > ve[v]) {
                // update 活动最早开始时间
                ve[v] = ve[u] + Adj[u][j].dis;
            }
        }
    }
    // 有向无环图转拓扑序列是否成功
    return topOrder.size() == n;
}

// 关键路径，不是有向无环图时返回-1，否则返回关键路径长度
int CriticalPath() {
    if (!topologicalSort()) {
        return -1;
    }
    // vl数组初始化，初始值为汇点(关键路径长度)ve值
    fill(vl, vl + n, ve[n - 1]);
    // 拓扑逆序列输出
    while (!topOrder.empty()) {
        // 取队首元素
        int u = topOrder.top();
        topOrder.pop();
        for (int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i].v;
            // 利用后继结点更新vl[u]
            if (vl[v] - Adj[u][i].dis < vl[u]) {
                // 利用得到的关键路径长度来反向求最迟开始时间
                vl[u] = vl[v] - Adj[u][i].dis;
            }
        }
    }
    // 遍历关键路径的结点
    for (int u = 0; u < n; u++) {
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v, dis = Adj[u][j].dis;
            int e = ve[u],  // 活动u的最早开始时间
                l = vl[v] - dis;    // 活动u的最迟开始时间
            // 显然，当e == l时，此点为关键路径
            if (e == l) {
                printf("%d -> %d\n", u, v);
            }
        }
    }
    // 返回关键路径的长度
    return ve[n - 1];
}

void initPara() {
    n = 6;
    inDegree[0] = 0;
    inDegree[1] = 1;
    inDegree[2] = 1;
    inDegree[3] = 1;
    inDegree[4] = 2;
    inDegree[5] = 1;
    Adj[0].push_back(Node(1, 30));
    Adj[0].push_back(Node(3, 40));
    Adj[1].push_back(Node(2, 40));
    Adj[2].push_back(Node(4, 50));
    Adj[3].push_back(Node(4, 40));
    Adj[4].push_back(Node(5, 70));
}

int main() {
    initPara();
    int ans = CriticalPath();
    printf("%d\n", ans);
}