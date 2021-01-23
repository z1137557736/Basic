#include<cstdio>
#include<set>

using namespace std;

int main() {
    // 内部采用红黑树，自动排序，且去重
    // unordered_set 内部采用散列(hash)实现，不排序，支持去重
    set<int> si;
    si.insert(3);
    si.insert(2);
    si.insert(4);
    si.insert(2);
    for (set<int>::iterator it = si.begin(); it != si.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    // find(2) 在set中找到2，并返回其迭代器
    printf("%d\n", *(si.find(2)));
    printf("%d", si.size());
    return 0;
}
