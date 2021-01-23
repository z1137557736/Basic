#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * 01背包问题(01 knapsack problem)
 * 01背包问题：有n种物品，每件物品的重量为w[i]，价值为c[i]。现在有一个容量为V的背包，问如何选取物品放入背包，使得背包内物品的总价最大。其中每种物品都只有一件
 * 样例：
 * 5 8  // n | V
 * 3 5 1 2 2    // w[i]
 * 4 5 2 1 3    // c[i]
 */

const int MAX_SIZE = 100;

// 物品数量 / 背包容量
int n, V;

// 物品[i]的重量 / 物品[i]的价格
int w[MAX_SIZE], c[MAX_SIZE];

// 最大背包物品总价
int maxW = 0;
/**
 * 使用DFS深度优先搜索，对于每件物品都有选与不选两种选择
 * 时间复杂度为O(2^n)
 * @param index 物品编号
 * @param sumW 累加重量
 * @param sumC 累加价格
 */
void DFS(int index, int sumW, int sumC) {
    // 递归边界，已完成对所有物品的选择
    if (index == n) {
        return;
    }
    // 不选择物品[index]
    DFS(index + 1, sumW, sumC);
    // note：此时为选择物品[index]，所以在判断时，都需要加上当前物品的重量与价格
    // 当累加重量 <= 背包容量，才继续往下执行，避免不必要的累加
    if (sumW + w[index] <= V) {
        // 累加价格 >= 最大背包物品总价
        if (sumC + c[index] >= maxW) {
            // 更新最大背包物品总价
            maxW = sumC + c[index];
        }
        // 选择物品[index]
        DFS(index + 1, sumW + w[index], sumC + c[index]);
    }
}

// d[i][v]表示前i件物品放入一个容量为v的背包可以获取的最大价值
int d[MAX_SIZE][MAX_SIZE];
// dp[V]即容量为V的背包可以获取到的最大价值
int dp[MAX_SIZE];

/**
 * 对于每件物品选与不选的问题，我们可以转换为一个只牵涉前i - 1件物品的问题
 * 如果不放第i件物品，那么问题就转化为”前i - 1件物品放入容量为v的背包中“
 * 如果放i件物品，那么问题就转化为”前i - 1件物品放入容量为v - w[i]的背包中 + v[i]“
 * 由于只有这两种策略，得到方程
 * d[i][v] = max{d[i - 1][v], d[i - 1][v - w[i]] + c[i]} (1 <= i <= n, w[i] <= v <= V)
 * 时间复杂度：O(nV)
 * 空间复杂度：O(V)
 */
void DP() {
    // 初始化边界
    for (int v = 0; v <= V; v++) {
        // 前0件物品放入一个容量为v的背包 最大价值肯定为 0
        dp[v] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int v = V; v >= w[i]; v--) {
            /**
             * 可以注意到，当状态转移方程计算第[i + 1]件物品时，第[i - 1]件物品的数据已经用不上了；
             * 这启发了我们，是不是只需开辟一个一维数组，用于保存上一件物品的数据
             * 考虑到状态转移方程总是需要正上方与左上方的数据，所以我们从右往左遍历即可
             */
            // 状态转移方程
            dp[v] = max(dp[v]   // 不选择物品
                    , dp[v - w[i]] + c[i]);   // 选择物品，note：d[i - 1][v - w[i]]是指前[i - 1]件背包容量为v - w[i]时的最大价值
        }
    }
    maxW = dp[V];
}

int main() {
    scanf("%d %d", &n, &V);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    // 从第一件物品开始选择，并初始化参数
    // DFS(0, 0, 0);
    DP();
    printf("%d", maxW);
}