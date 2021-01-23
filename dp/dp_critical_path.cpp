#include <cstdio>
#include <algorithm>

using namespace std;
/**
 * 简便版：求解DAG上的关键路径
 */

const int INF = 0x3fffffff; // 无穷大
const int MAX_SIZE = 1000;

// 邻接矩阵
int G[MAX_SIZE][MAX_SIZE] = {};
// 顶点数量 / 存放d[i]的从i点出发的最长路径
int n, d[MAX_SIZE] = {};
// 存放顶点i的后继结点
int choice[MAX_SIZE];

// 求解DAG上的关键路径的长度
int DP(int i) {
    // d[i]已有从该点出发的最长路径，直接返回
    if (d[i] > 0) return d[i];
    // 枚举顶点i所有的边
    for (int j = 0; j < n; j++) {
        // 当边权存在时
        if (G[i][j] > 0) {
            // 大于d[i]则更新，深度优先搜索
            //d[i] = max(d[i], DP(j) + G[i][j]);
            int temp = DP(j) + G[i][j];
            // 可以获取更大的路径长度，当有多条最长路径时，则会选择字典序最小的那条路径，想一想为什么这块代码自动实现了此功能
            if (temp > d[i]) {  // 因为j从0开始，且temp 严格大于 d[i]时，才会更新。这使得其默认则使用字典序最小的路径
                // 更新d[i]
                d[i] = temp;
                // 更新顶点i处的后继结点
                choice[i] = j;
            }
        }
    }
    // 所有出度0的顶点为边界 or 已求解 --> 直接返回d[i]
    return d[i];
}

// 后继结点 -> 关键路径的输出
void printPath(int i) {
    printf("%d ", i);
    // 将choice的默认值设置为INF
    if (choice[i] != INF) {
        printPath(choice[i]);
    }
}

// d2[i]存放以i为终点的最长路径长度
int d2[MAX_SIZE];

// 存放顶点i的前驱结点
int choice2[MAX_SIZE];

// 求解DAG上的关键路径的长度，顶点i即为终点
int DP2(int i) {
    // 已有结果，直接返回
    if (d2[i] > 0) return d2[i];
    for (int j = 0; j < n; j++) {
        // 枚举顶点i的入边
        if (G[j][i] > 0) {
            int temp = DP2(j) + G[j][i];
            // 缺点：不便于得到字典序最小的方案，因为总是以接近终点的字典序来排序
            if (temp > d2[i]) {
                d2[i] = temp;
                // 记录顶点i的前驱结点j
                choice2[i] = j;
            }
        }
    }
    // 以入度0为边界 or 已求解 --> 直接返回d[i]
    return d2[i];
}

// 前驱结点 -> 关键路径的输出
void printPath2(int i) {
    // 将choice的默认值设置为INF
    if (choice2[i] != INF) {
        printPath2(choice2[i]);
    }
    printf("%d ", i);
}

void initParam() {
    n = 5;
    fill(choice, choice + n, INF);
    fill(choice2, choice2 + n, INF);
    G[0][1] = 2;
    G[0][2] = 3;
    G[1][3] = 7;
    G[3][4] = 1;
    G[2][4] = 7;
}

int main() {
    initParam();
    // 以d[i]为起点的最长路径
    printf("%d\n", DP(0));
    printPath(0);
    printf("\n");
    // 以d[i]为终点的最长路径
    printf("%d\n", DP2(4));
    printPath2(4);
    return 0;
}