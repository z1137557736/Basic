#include <cstdio>
#include <queue>

using namespace std;

/**
 * 走迷宫(求最短路程)
 * "*"代表不可通过的墙壁，"."代表平地，"S"为起点，"T"为终点
 */

struct Node {
    // 坐标
    int x;
    int y;
    // 当前走的步数
    int step;
}S, T, temp;  // 起点坐标、终点坐标、temp临时结点

const int MAX_VALUE = 100;
// n为行 m为列
int n, m;
// 矩阵
char matrix[MAX_VALUE][MAX_VALUE];
// (x, y)坐标是否被访问过
bool inq[MAX_VALUE][MAX_VALUE] = {false};
// 定义x、y轴的增量(上下左右)
int X[4] = {0, 0, -1, 1};
int Y[4] = {1, -1, 0, 0};
// 定义队列
queue<Node> q;

// 判断(x, y)是否需要访问
bool judge(int x, int y) {
    // 边界判断
    if (x >=n || x < 0 || y >= m || y < 0) {
        return false;
    }
    // 当前(x, y)为'*' 或已入过队
    if (matrix[x][y] == '*' || inq[x][y]) {
        return false;
    }
    return true;
}

// 利用广度优先搜索的步骤来计算最短路程
int BFS() {
    q.push(S);
    while (!q.empty()) {
        // 获取队首结点
        Node top = q.front();
        q.pop();
        // 已经到达终点，退出循环
        if (top.x == T.x && top.y == T.y) {
            return top.step;
        }
        // 枚举(x, y)上下左右的结点
        for (int i = 0; i < 4; i++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (judge(newX, newY)) {
                temp.x = newX;
                temp.y = newY;
                // 此结点为队首结点的派生结点，步数+1
                temp.step = top.step + 1;
                // 队列会复制一个temp的副本，将副本入队
                // 此时有两个对象，所以temp的改变不会影响入队元素的改变
                q.push(temp);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        // 过滤掉每一行的换行
        getchar();
        for (int j = 0; j < m; j++) {
            // 初始化矩阵
            matrix[i][j] = getchar();
        }
        // char数组以 '\0' 结束
        matrix[i][m + 1] = '\0';
    }
    // 起始坐标
    scanf("%d %d %d %d", &S.x, &S.y, &T.x, &T.y);
    // 起点为第0步
    S.step = 0;
    printf("%d\n", BFS());
}