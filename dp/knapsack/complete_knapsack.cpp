#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * 完全背包(complete knapsack)
 * 完全背包：有n种物品，每种物品的单件重量为w[i], 价值为c[i]。现有一个容量为V的背包，问如何选区物品放入背包，使得背包内物品的总价值最大。其中每种物品都有无穷件。
 */

const int MAX_SIZE = 100;

// 物品数量 / 背包容量
int n, V;

// 物品[i]的重量 / 物品[i]的价格
int w[MAX_SIZE], c[MAX_SIZE];

// 最大背包物品总价
int maxW = 0;

// dp[V]即容量为V的背包可以获取到的最大价值
int dp[MAX_SIZE];

/**
 * 在01背包种对于每件物品选与不选的问题。而在完全背包中，每件物品有不选或选1次、2次...n次，直到背包容量装满为止
 * 如果不放第i件物品，那么问题就转化为”前i - 1件物品放入容量为v的背包中“
 * 由于只有这两种策略，得到方程
 * dp[v] = max{d[v], dp[v - w[i]] + c[i]} (1 <= i <= n, w[i] <= v <= V)
 * 时间复杂度：O(nV)
 * 空间复杂度：O(V)
 */
void DP() {
    // 初始化边界
    for (int v = 0; v <= V; v++) {
        dp[v] = 0;
    }
    for (int i = 1; i <= n; i++) {
        // 必须正向枚举；显然如果让v从小到大枚举，dp[v - w[i]]总是先被计算出来
        for (int v = w[i]; v <= V; v++) {
            // 状态转移方程
            dp[v] = max(dp[v]   // 不选择物品
                    , dp[v - w[i]] + c[i]);   // 选择物品；应该注意到：此时的dp[v]已经不是参考上一件物品的数据，而是参考同一件物品挑选多次的数据
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