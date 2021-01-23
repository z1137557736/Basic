#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * 数塔问题，1层有1个数，2层有2个数，...n层有n个数字。将路径上的所有数相加之和最大为多少？
 */

const int MAX_SIZE = 100;

// 定义二维数组来存储数塔
int f[MAX_SIZE][MAX_SIZE] = {};

// 记录该点处路径的最大和
int dp[MAX_SIZE][MAX_SIZE] = {};

// 塔层数
int n;

/**
 * 使用递推，自底向上(Bottom-up Approach)
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n^2)
 */
void f1() {
    // 从倒数第二层开始计算
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            // 状态转移方程
            dp[i][j] = max(dp[i + 1][j] , dp[i + 1][j + 1])
                       + f[i][j];
        }
    }
}

// 使用递推，自顶向下(Top-down Approach)
int f2(int i, int j) {
    // 递归边界
    if (f[i][j] == dp[i][j]) return dp[i][j];
    // 递归式
    else {
        return dp[i][j] = max(f2(i + 1, j), f2(i + 1, j + 1)) + f[i][j];
    }
}

int main() {
    // 5
    // 5
    // 8 3
    // 12 7 16
    // 4 10 11 6
    // 9 5 3 9 4
    scanf("%d", &n);
    // 注意到，下标从1开始
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &f[i][j]);
        }
    }
    // 设置递归边界
    for (int j = 1; j <= n; j++) {
        dp[n][j] = f[n][j];
    }
    printf("%d\n", f2(1, 1));
    // 顶部则为最大值
    printf("%d\n", dp[1][1]);
    return 0;
}