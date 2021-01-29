#include <iostream>
#include <string>

using namespace std;

string S, P;

// 暴力匹配
bool bruteForce() {
    // i为字符串S的位置 / j为字符串P的位置
    int i = 0, j = 0;
    // 当遍历完字符串P or S时，退出循环
    while (i < S.length() && j < P.length()) {
        if (S[i] == P[j]) {
            // 当前字符匹配成功，进行下一个字符匹配
            i++;
            j++;
        } else {
            // 当字符匹配不成功时，回退继续找
            i = i - j + 1;
            // 匹配字符串P从0开始匹配
            j = 0;
        }
    }
    return j == P.length();
}

int main() {
    getline(cin, S);
    getline(cin, P);
    cout << bruteForce() << endl;
}