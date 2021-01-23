#include "iostream"
#include "string"
#include "utility"

using namespace std;

int pair_main() {
    // 将两个元素绑定成一个元素
    pair<string, int> fruit("grape", 10);
    cout << fruit.first << ' ' << fruit.second << endl;
    return 0;
}