#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * 字符串hash进阶：字符串hash是指将一个字符串S映射为一个整数，使得该整数可以尽可能的唯一地代表这个字符串S。
 * 在实践中发现，如果把进制数设置为一个10^7级别的素数(如10000019)，同时把mod设置为一个10^9级别的素数(如1000000007)，其冲突的概率会非常小
 * 公式：H[i] = (H[i - 1] * P + index(str[i])) % mod
 */

const int P = 10000019; // 等价于 1e7 + 19
const int MOD = 1000000007; // 等价于 1e9 + 7

string S;
vector<long long> V;

long long hashCode() {
    // 防止整数溢出
    long long H = 0;
    for (int i = 0; i < S.length(); i++) {
        // 进制转换 + 取模
        H = (H * P + (S[i] - 'a')) % MOD;
    }
    return H;
}

int main() {
    // 当S 等于 "#" 时退出循环
    while (getline(cin, S), S != "#") {
        V.push_back(hashCode());
    }
    // 排序
    sort(V.begin(), V.end());
    int ans = 0;
    for (int i = 0; i < V.size(); i++) {
        printf("%d\n", V[i]);
        // i == 0 或 前后两个数不相等
        if (i == 0 || V[i - 1] != V[i]) {
            ans++;
        }
    }
    printf("%d", ans);
}