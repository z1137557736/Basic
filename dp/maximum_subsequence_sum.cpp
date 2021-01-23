#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * 最大连续子序列和：给定一个数组序列A[1],A[2],...,A[n]，求i,j(1 <= i <= j < n)，使得A[i] + ... + A[j]最大，输出这个最大和
 */

const int MAX_SIZE = 100;

// 基于数组的序列 / 序列长度
int num[MAX_SIZE], n;

/**
 * 暴力搜索法，复杂度为O(n^3)
 * 区间[i, j]
 */
int bruteForce() {
    int maxValue = 0, thisValue;
    // 以i为左端点
    for (int i = 0; i < n; i++) {
        // 以j为右端点
        for (int j = i + 1; j < n; j++) {
            thisValue = 0;
            // [i, j)区间，累加这个区间的数之和
            for (int k = i; k < j; k++) {
                // 累加子序列和
                thisValue += num[k];
                // 当前子序列和 大于 最大子序列和
                if (thisValue > maxValue) {
                    // 更新最大子序列和
                    maxValue = thisValue;
                }
            }
        }
    }
    return maxValue;
}

/**
 * 改良版：暴力搜索法，复杂度为O(n^2)
 * 区间[i, n]：可以发现并不需要右端点j，直接以n为右端点也可以实现
 */
int bruteForceFaster() {
    int maxValue = 0, thisValue;
    for (int i = 0; i < n; i++) {
        thisValue = 0;
        // 区间[i, n)，以i为左端点，n为右端点，进行累加
        for (int k = i; k < n; k++) {
            // 累加子序列和
            thisValue += num[k];
            // 当前子序列和 大于 最大子序列和
            if (thisValue > maxValue) {
                // 更新最大子序列和
                maxValue = thisValue;
            }
        }
    }
    return maxValue;
}

// 返回三个数的最大值
int max3(int a, int b, int c) {
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

/**
 * 利用分而治之的思想来找我们的最长子序列之和，复杂度O(nlog(n))
 * @param left 左端点
 * @param right 右端点
 * @return 最长子序列之和
 */
int divideAndConquer(int left, int right) {
    if (left == right) {
        // num[left] < 0 时不参与计算
        return num[left] > 0 ? num[left] : 0;
    }
    // 左区间的子序列之和 / 右区间的子序列之和
    int sumLeft, sumRight;
    // 分割点
    int center = (left + right) / 2;
    sumLeft = divideAndConquer(left, center);
    sumRight = divideAndConquer(center + 1, right);
    // 跨区间的子序列之和(从中间往两边伸展，才可保证其为连续子序列)
    int sumTotal;
    int maxLeft = 0, tempLeft = 0;
    // 先处理左子区间的子序列
    for (int i = center; i >= left; i--) {
        tempLeft += num[i];
        // 当前子序列和 大于 最大子序列和
        if (tempLeft > maxLeft) {
            // 更新最大子序列和
            maxLeft = tempLeft;
        }
    }
    int maxRight = 0, tempRight = 0;
    // 再处理右子区间的子序列
    for (int i = center + 1; i <= right; i++) {
        tempRight += num[i];
        // 当前子序列和 大于 最大子序列和
        if (tempRight > maxRight) {
            // 更新最大子序列和
            maxRight = tempRight;
        }
    }
    // 跨区间最大子序列和 = 最大左子序列和(从右向左遍历) + 最大右子序列和(从左向右遍历)
    sumTotal = maxLeft + maxRight;
    // 左子区间最大子序列和 / 右子区间最大子序列和 / 跨区间最大子序列和
    return max3(sumLeft, sumRight, sumTotal);
}

/**
 * 在线处理算法，复杂度为O(n)
 */
int onlineProcess() {
    int maxValue = 0, thisValue = 0;
    for (int i = 0; i < n; i++) {
        // 累加子序列和
        thisValue += num[i];
        // 当前子序列和 大于 最大子序列和
        if (thisValue > maxValue) {
            // 更新最大子序列和
            maxValue = thisValue;
        } else if (thisValue < 0) { // 显然，当thisValue小于0时，并不会使得后面的子序列和变大
            // 将thisValue 重置为0
            thisValue = 0;
        }
    }
    return maxValue;
}

// 存放以num[i]结尾的最大子序列和
int dp[MAX_SIZE] = {};

/**
 * 动态规划，获取最大子序列长度；复杂度为O(n)
 */
int dynamicProgramming() {
    // 最大连续子序列和
    int maxValue = 0;
    // 初始边界
    dp[0] = num[0];
    // 区间[1, n)
    for (int i = 1; i < n; i++) {
        // 状态转移方程
        dp[i] = max(dp[i - 1] + num[i], num[i]);
        // dp[i]存放以num[i]结尾的最大子序列和
        if (dp[i] > maxValue) {
            // 大于则更新
            maxValue = dp[i];
        }
    }
    return maxValue;
}

int main() {
    // 6
    // -2 11 -4 13 -5 -2
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    printf("%d", dynamicProgramming());
    return 0;
}