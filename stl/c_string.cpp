#include <iostream>
#include <string>

using namespace std;

int main() {
    // 字符串
    string str = "abcd";
    for (int i = 0; i < str.length(); i++) {
        printf("%c ", str[i]);
    }
    printf("\n");
    // 通过printf输出，需要调用 c_str()方法转成char数组
    printf("%s\n", str.c_str());
    // 迭代取指针
    for (string::iterator it = str.begin(); it != str.end(); it++) {
        // *it 指针取值
        printf("%c ", *it);
    }
    printf("\n");
    string str2 = "我睡觉了1";
    cout << str2.length() << endl;
}