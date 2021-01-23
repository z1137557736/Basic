#include <cstdio>
#include <algorithm>
#include <cstring>

/**
 * LIS(最长上升子序列)：在一个数字序列中，找到一个最长的子序列（可以不连续），使得这个子序列是不下降(非递减的)的，返回其长度
 */

using namespace std;

const int MAX_SIZE = 100;

// 基于数组的序列 / 序列长度
int num[MAX_SIZE], n;

// 存放以num[j]结尾最长子序列的长度
int dp[MAX_SIZE];

// 复杂度为O(n^2)
int dynamicProgramming() {
    int ans = -1;
    // 初始化(假设每个元素各个构成一个长度为1的最长子序列)
    fill(dp, dp + n, 1);
    // 以i为左端点，j为右端点，进行遍历
    for (int j = 1; j < n; j++) {
        // 区间j[0, i)
        for (int i = 0; i < j; i++) {
            // 保证其为非递减的
            if (num[i] <= num[j]) {
                // 状态转移方程，两者之间取一个较大值
                dp[j] = max(dp[i] + 1   // 为以i点结尾的最长子序列长度 + 1
                        , dp[j]);
            }
        }
        // 存放以num[i]结尾最长的子序列的长度
        if (dp[j] > ans) {
            // 大于则更新
            ans = dp[j];
        }
    }
    return ans;
}

int main() {
    // 8
    // 1 2 3 -9 3 9 0 11
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    printf("%d", dynamicProgramming());

}