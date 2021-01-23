#include "iostream"
#include "algorithm"

using namespace std;

int main () {
    int a[10] = {1, 2, 2, 3, 3, 3, 5, 5, 5, 5};
    // 数组会返回其指针，容器则会返回其迭代器
    // 返回第一个大于等于val的数
    int* lowerPos = lower_bound(a, a + 10, 5);
    // 返回第一个大于val的数
    int* upperPos = upper_bound(a, a + 10, 5);
    // 取下标(指针与首元素指针的距离即下标)
    printf("%d\n", lowerPos - a);
    printf("%d\n", upperPos - a);
}