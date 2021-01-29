#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/**
 * 引入公式：
 * 首先我们考虑直接求解字符串的子串的hash值，也就是求解H[i, j]，已知散列函数如下：
 * H[i] = H[i - 1] * P + index(S[i])
 * 从进制转换思考，H[i, j]实际上等于把S[i, j]从P进制转成了十进制，可得以下函数：
 * H[i, j] = index(S[i]) * P^j-i + index(S[i - 1]) * P^j-i-1 + ... + index(S[j]) * P^0
 * 通过H[j]的散列函数可以推导出H[i, j]：
 * H[j] = H[j - 1] * P + index(S[j])
 *      = (H[j - 2] * P + index(S[j - 2])) * P + index(S[j])
 *      = H[j - 2] * P^2 + index(S[j - 2]) * P + index(S[j])        // Note: P^2 = P^j-(j - 2)
 *      = ...
 *      = H[i - 1] * P^j-i+1 + index(S[i]) * P^j-i + index(S[i - 1]) * P^j-i-1 + ... + index(S[j]) * P^0
 *      = H[i - 1] * P^j-i+1 + H[i, j]
 * ∴ 有等式成立：H[i, j] = H[j] - H[i - 1] * P^j-i+1
 * 最终公式（取模避免负数的出现）：H[i, j] = ((H[j] - H[i - 1] * P^j-i+1) % mod + mod) % mod
 *
 * 问题：输入两个长度均不超过1000的字符串，求它们的最长公共子串的长度。如字符串"ILoveYou"与"YouDontLoveMe"的
 * 最长公共子串是"Love"而不是"You"，因此输出4。（Note：子串必须连续）
 */

typedef long long LL;
const LL P = 10000019;  // 计算Hash时的模数
const LL MOD = 1000000007;  // 进制数
const int MAX_SIZE = 1010;  // 字符串最长长度
// 存放P进制数的幂 / S1的Hash / S2的Hash
LL powP[MAX_SIZE], H1[MAX_SIZE], H2[MAX_SIZE];
// pre1存放S1所有的子串以及其子串的区间 / S2同理
vector<pair<int, pair<int, int>>> pr1, pr2;
// 存放字符串
string S1, S2;

// 初始化所有幂
void init(int len) {
    powP[0] = 1;
    for (int i = 1; i <= len; i++) {
        powP[i] = (powP[i - 1] * P) % MOD;
    }
}

/**
 * 字符串转Hash
 * @param H Hash数组
 * @param S 字符串
 */
void calcHash(LL H[], string &S) {
    // 初始第一步
    H[0] = S[0];
    for (int i = 1; i < S.length(); i++) {
        // 由散列公式可得
        H[i] = ((H[i - 1] * P) + S[i]) % MOD;
    }
}

/**
 * 返回子串S[i, j]的Hash码H[i, j]
 * @param H Hash数组
 * @param i 起始端点
 * @param j 终点端点
 * @return
 */
int calcSubHash(LL H[], int i, int j) {
    if (i == 0) {
        // 直接返回
        return H[j];
    } else {
        return ((H[j] - H[i - 1] * powP[j - i + 1]) % MOD + MOD) % MOD;
    }
}

// 枚举出所有子串的Hash以及其长度
void subHash(LL H[], int len, vector<pair<int, pair<int, int>>> &pr) {
    // 定义区间[i, j]
    for (int i = 0; i < len; i++) {
        // Node: j >= i
        for (int j = i; j < len; j++) {
            // 子串的Hash / 子串的长度
            pr.push_back(make_pair(calcSubHash(H, i, j), make_pair(i , j)));
        }
    }
}

// 获取最长公共子串
string getMaxStr() {
    // 最大长度 / 字符串起始位置 / 字符串截止位置
    int maxLen = 0, start, end;
    for (int i = 0; i < pr1.size(); i++) {
        for (int j = 0; j < pr2.size(); j++) {
            // 当子串的Hash相等时
            if (pr1[i].first == pr2[j].first) {
                // 临时存放字符串起始位置，这里返回S1和S2的起始位置都可以
                int ts = pr1[i].second.first;
                int te = pr1[i].second.second;
                if (te - ts + 1 > maxLen) {
                    // 更新最长公共子串的长度
                    maxLen = te - ts + 1;
                    start = ts;
                    end = te;
                }
            }
        }
    }
    // 返回S1起始位置的子串，Note：substr的区间是闭区间
    return S1.substr(start, end);
}

int main() {
    getline(cin, S1);
    getline(cin, S2);
    // 初始化幂
    init(max(S1.length(), S2.length()));
    // 计算字符串的Hash
    calcHash(H1, S1);
    calcHash(H2, S2);
    // 通过字符串的Hash来推算其子串的Hash
    subHash(H1, S1.length(), pr1);
    subHash(H2, S2.length(), pr2);
    cout << getMaxStr() << endl;
}