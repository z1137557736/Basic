#include <iostream>
#include <string>
#include <map>

using namespace std;

int main () {
    map<string, int> mp;
    mp["0"] = 10;
    mp["1"] = 20;
    printf("%d\n", mp["0"]);
    // 底层使用红黑树实现，在建立映射的过程中会自动实现从小到大(字典序)的排序
    map<int, char> mp2;
    mp2[0] = 'A';
    mp2[1] = 'B';
    mp2[2] = 'C';
    mp2.erase(2);
    // 循环指针法，指针自增
    for (auto it = mp2.begin(); it != mp2.end(); it++) {
        // 指针对象取值法(point -> property)
        cout << it -> first << " " << (*it).second << endl;
    }
}