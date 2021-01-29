#include <cstdio>
#include <vector>

using namespace std;

int main() {
    // 自动变长数组
    vector<int> vi;
    for (int i = 1; i <= 5; i++) {
        vi.push_back(i);
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", vi[i]);
    }
    printf("\n");
    // vi.begin()为获取vi的首元素的指针
    vector<int>::iterator it = vi.begin();
    for (int i = 0; i < 5; i++) {
        // 偏移指针并取指针的值
        printf("%d ", *(it + i));
    }
    printf("\n");
    // 左闭右开的思想，vi.begin()获取的是最后一个元素的下一个
    for (auto it = vi.begin(); it != vi.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    return 0;
}
