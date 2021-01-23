#include <iostream>
#include <string>

using namespace std;
/**
 * 最长回文子串（正反读都一样的字符串）：给出你一个字符串S，求S的最长回文子串的长度
 * 常用算法有：暴力破解、动态规划、中心扩散、Manacher(马拉车)
 * 样例：
 * 字符串"PATZJUJZTACCBCC"的最长回文字符串为“ATZJUJZTA”，长度为9
 */

const int MAX_SIZE = 100;

// 字符串S
string S;

// 判断区间[i, j]是否为回文串，显然，不管是奇位数回文串还是偶位数的回文串都可以验证
bool isValid(int i, int j) {
    while (i < j) {
        if (S[i] != S[j]) {
            return false;
        }
        // 枚举子串的左边界与右边界
        i++;
        j--;
    }
    return true;
}

/**
 * bruteForce 暴力破解法
 * 时间复杂度为O(n^3)
 * 空间复杂度为O(1)
 */
string bfLongestPalindrome() {
    int len = S.length();
    // 特判
    if (len < 2) {
        return S;
    }
    // 最长回文子串
    string ans;
    // 最长回文子串长度
    int maxValue = 0, start;
    for (int i = 0; i < len; i++) {
        for (int j = 1; j < len; j++) {
            // 区间长度(子串长度)
            int q = j - i + 1;
            // 区间长度 > 最长回文子串长度 && 当前子串为回文串
            if (q > maxValue && isValid(i, j)) {
                // 更新最长回文子串长度
                maxValue = q;
                // 最长回文子串起始位置
                start = i;
            }
        }
    }
    return S.substr(start, maxValue);
}

// dp[i][j]表示S[i]-S[j]所表示的子串是否为回文子串，是则为1，不是则为0.
bool dp[MAX_SIZE][MAX_SIZE] = {};

/**
 * 动态规划（填表法）,总是先得到小子串的回文判断，然后大子串才能参考小子串的判定结果
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n^2)，注意到dp[n][n]为二维数组
 */
string dpLongestPalindrome() {
    int len = S.length();
    // 特判
    if (len < 2) {
        return S;
    }
    // **** 初始化对角线(舍)；以j为行，i为列，对角线下半部分进行填表 ****
    /*for (int i = 0; i < len; i++) {
        dp[i][i] = true;
    }*/
    int start, maxSize = 0;
    // i为左端点，j为右端点，i 恒小于 j
    for (int j = 1; j < len; j++) {
        for (int i = 0; i < j; i++) {
            // 端值不相等
            if (S[i] != S[j]) {
                dp[i][j] = false;
            } else {
                /**
                 * 边界条件是：表达式[i + 1, j - 1]不构成区间，即长度严格小于2，即有方程 j - 1 - (i + 1) + 1 < 2
                 * 解得 j - i < 3, 即 j - i + 1 < 4；结论很显然，区间长度为3或2时，不需要获取其子串判定结果，即可直接下结论
                 */
                if (j - i < 3) {
                    // 区间长度小于4，无需小子串的判定结果
                    dp[i][j] = true;
                } else {
                    // 状态转移方程(S[i] == S[j]，且子串为回文串，则区间S[i, j]的子串必为回文串)
                    dp[i][j] = dp[i + 1][j - 1];
                }
                // 当前区间长度
                int p = j - i + 1;
                if (dp[i][j] && p > maxSize) {
                    // 最长回文子串长度
                    maxSize = p;
                    // 最长回文子串的起始文职
                    start = i;
                }
            }
        }
    }
    return S.substr(start, maxSize);
}

int main() {
    cin >> S;
    cout << dpLongestPalindrome() << endl;
    return 0;
}