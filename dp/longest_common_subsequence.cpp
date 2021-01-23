#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

/**
 * LCS(最长公共子序列)：给定两个字符串(或数字序列)A和B，求一个字符串，使得这个字符串是A和B的最长公共部分(子序列可以不连续)
 */

const int MAX_SIZE = 100;

// 矩阵：字符串A的i号位和字符串j号位之前的LCS长度（初始化边界为0）
int dp[MAX_SIZE][MAX_SIZE] = {};

// 字符串 A / 字符串 B
char A[MAX_SIZE], B[MAX_SIZE];

// 算法复杂度为O(n^2)
int main() {
    // sadstory
    // adminsorry
    gets(A + 1);    // 从下标为1开始读取
    gets(B + 1);
    int lenA = strlen(A + 1),   // 从A + 1开始扫描，直到碰到第一个字符串结束符'\0'为止
        lenB = strlen(B + 1);
    // 两个字符串组成矩阵
    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            // 当字符相等时
            if (A[i] == B[j]) {
                // 上一位LCS长度 + 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {    // 不相等时
                // 如：样例中dp[3][3]表示"sad"和"adm"的LCS长度，当我们发现A[3]和B[3]中'd'和'm'不相等时
                // dp[3][3]需要继承"sa"和"adm" 或 "sad"和"ad"中较大的LCS长度(显然前者的LCS长度为1，后者为2，所以取得后者)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("%d", dp[lenA][lenB]);
    return 0;
}

