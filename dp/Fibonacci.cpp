#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * DP(Dynamic Programming)：动态规划是一种用来解决一类最优化问题的算法思想。
 * 动态规划：动态规划将一个复杂的问题分解为若干个子问题，通过综合子问题的最优解来得到原问题的最优解。
 * 简单来说，动态规划会将子问题的解记录下来，这样当下一次碰到同样的子问题时，就可以直接使用之前的结果，而不是重复计算。
 * 重叠子问题：如果一个问题可以被分解为若干个子问题，且这些子问题会重复出现，那么就称这个问题拥有重叠子问题（Overlapping Subproblems）
 * 最优子结构：如果一个问题得最优解可以由其子问题得最优解有效地构造出来，那么称这个问题拥有最优子结构(Optimal Substructure)
 * 所以：一个问题必须拥有重叠子问题和最优子结构，才可使用动态规划去解决。
 *
 * 区别：
 * 动态规划和分治：
 * 相同点：分治和动态规划都是将问题分为最小子问题，然后合并最小子问题的解，来得到原问题的解。
 * 不同点：分治法分解出来的子问题是不重叠的，而动态规划的子问题是重叠的
 *
 * 贪心与动态规划：
 * 相同点：贪心与动态规划都要求原问题有最优子结构。
 * 不同点：贪心是单链方式的最优子结构（采用自顶向下的方式），而动态规划是全局范围的最优子结构（自顶向下与自底向上两种方式都行）
 *
 * 状态的无后效性：当前状态记录了历史信息，一旦当前状态确定，就不会改变，且未来的决策只能在已有的一个或若干个状态的基础上运行。
 * 简单来说，从宇宙的角度来说，未来是基于过去发展运行的，但无法改变过去。
 * 所以：设计一个拥有无后效性的状态与相应的状态转移方程才是动态规划的核心。
 */

const int MAX_SIZE = 100;

int dp[MAX_SIZE] = {};

/**
 * 示例：1 1 2 3 5 8 13 21 ...
 * 记忆化搜索，将复杂度O(2^n) ==> O(n)
 */
int Fibonacci(int n) {
    // n为索引，递归边界
    if (n == 1 || n == 2) return 1;
    else {
        // 利用空间来换取时间，避免重复计算
        if (dp[n] == -1) {
            // 计算F(n)并保存到dp[n]
            dp[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
        }
        // 返回dp[n]
        return dp[n];
    }
}

int main() {
    fill(dp, dp + MAX_SIZE, -1);
    printf("%d\n", Fibonacci(30));
    return 0;
}