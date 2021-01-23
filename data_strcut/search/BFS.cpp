#include <cstdio>
#include <queue>

/**
 * BFS breadth first search(广度优先搜索，一般使用队列实现)
 * 先在队列中放入一个点A(先进先出)
 * 第一层：取出队首元素A，将A相邻的B、C入队，此时队内元素为{B, C}
 * 第二层：取出队首元素B，将B相邻的D、E入队，此时对内元素为{C, D, E}
 * 第二层：取出队首元素C，将C相邻的F、G入队，此时对内元素为{D, E, F, G}
 * 第三层：取出D...
 * 循环直到队列为空，或者到达某种自定义边界
 */
using namespace std;

// 定义一个坐标轴结点
struct Node {
    int x;
    int y;
} temp;
const int MAX_VALUE = 100;
// 矩阵的大小n*m
int n, m;
// 定义Node队列
queue<Node> q;
// 定义矩阵
int matrix[MAX_VALUE][MAX_VALUE];
// 记录(x, y)是否入过队
bool inq[MAX_VALUE][MAX_VALUE] = {false};
// 定义两个增量数组，相邻上下左右的四个位置：(x, y + 1) (x, y - 1) (x - 1, y) (x + 1, y)
int X[4] = {0, 0, -1, 1};
int Y[4] = {1, -1, 0, 0};

// 判断(x, y)是否需要去访问
bool judge(int x, int y) {
    // 下标是否越界
    if (x >= n || x < 0 || y >= m || y < 0) {
        return false;
    }
    // 当前(x, y)为0，或(x, y)已经入过队(避免重复入队)
    if (matrix[x][y] == 0 || inq[x][y]) {
        return false;
    }
    return true;
}

// 深度优先搜索标记一块区域
void DFS(int x, int y) {
    // 标记为已访问，避免重复搜索
    inq[x][y] = true;
    for (int i = 0; i < 4; i++) {
        // 生成上下左右的坐标
        int newX = X[i] + x;
        int newY = Y[i] + y;
        // 递归边界
        if (judge(newX, newY)) {
            // 未被访问过
            DFS(newX, newY);
        }
    }
}

// 广度优先搜索标记一块区域
void BFS(int x, int y) {
    // 先将结点放入队列
    Node node;
    node.x = x;
    node.y = y;
    q.push(node);
    while (!q.empty()) {
        // 取出队首元素
        Node top = q.front();
        q.pop();
        // 标识为已入队
        inq[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (judge(newX, newY)) {
                // 需要访问，入队
                temp.x = newX;
                temp.y = newY;
                q.push(temp);
                // 标识为已入队
                inq[temp.x][temp.y] = true;
            }
        }
    }
}

/**
 * 寻找矩阵以1形成的块数
 */
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 初始化矩阵
            scanf("%d", &matrix[i][j]);
        }
    }
    // 形成的块数
    int ans = 0;
    // 枚举矩阵
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            // 当前矩阵(x , y)为1，且未被访问过(避免同一个块重复入队)
            if (matrix[x][y] == 1 && !inq[x][y]) {
                // 块数+1
                ans++;
                // 访问整个块，并将它们标记为已访问
                DFS(x, y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}