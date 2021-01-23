#include <iostream>
#include <string>

using namespace std;

int n;	// 有效位数

// 处理成科学计数法，e为引用变量的指数
string deal(string s, int& e) {
    // k 为下标
    int k = 0;
    // 将首位数为0的去掉
    while (s.length() > 0 && s[0] == '0') {
        s.erase(s.begin());
    }
    // 小于0的小数
    if (s[0] == '.') {
        // 去掉小数点
        s.erase(s.begin());
        //  将首位数为0的去掉
        while (s.length() > 0 && s[0] == '0') {
            s.erase(s.begin());
            // 指数减1，如：0.0014 = 0.14 * 1e-2
            e--;
        }
    } else {
        // 大于0的数，判断是n位数(10^n次方)
        while (k < s.length() && s[k] != '.') {
            // 指数加1，如：123.1 = 0.123 * 1e3
            e++;
            // 下标加1
            k++;
        }
        // while结束后 k < s.length() 还成立，说明找到了小数点
        if (k < s.length()) {
            // 去掉小数点
            s.erase(s.begin() + e);
        }
    }
    // 传进来数值的是，0.000类型的
    if (s.length() == 0) {
        e = 0;
    }
    string res;
    // k 为下标
    k = 0;
    // 只取有效位，少于有效位补0
    while (k < n) {
        if (k < s.length()) res += s[k];
        else res += '0';
        k++;
    }
    return res;
}

int main() {
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);
    if (s3 == s4 && e1 == e2) {
        cout << "YES 0." << s3 << "*10^" << e1 << endl;
    } else {
        cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
    }
    return 0;
}
