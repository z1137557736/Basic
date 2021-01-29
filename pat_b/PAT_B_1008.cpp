#include <cstdio>

/**
 * 数组元素循环右移问题
 * 一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（≥0）个位置
 */

const int MAX_SIZE = 105;

int A[MAX_SIZE] = {};

int main() {
    // 数组元素的数量 / 右移位数
    int n, M;
    scanf("%d%d", &n, &M);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    // 取余，防止M大于n时重复的移动
    M = M % n;
    // 记录右移位数
    int temp = M;
    /**
     * 可以发现，我们不需要移动数组，也可实现数组的一个元素假右移后的输出
     * 主要思路：将数组分为两个区间来输出即可
     * 利用方程 k = n - M--，可以输出伪右移数组的起始元素，当M自减 = 0时，再从原数组的起始位置输出，有 k = i - M
     * 即有方程 k = n - M--, M > 0 和 k = i - M, M == 0
     */
    for (int i = 0; i < n; i++) {
        int k;
        if (temp > 0) {
            // 伪右移数组的起始元素
            k = n - temp--;
        } else {
            // 从原数组的起始位置输出
            k = i - M;
        }
        printf("%d", A[k]);
        // 加空格
        if (i < n - 1) {
            printf(" ");
        }
    }
    return 0;
}