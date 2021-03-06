#include <cstdio>
#include <map>

using namespace std;

/**
 * A+B for Polynomials
 * 题意：关于多项式加法
 */

int n;
// 存放多项式结果
map<int, double> mp;

int main() {
    // 多项式的项数 | 指数
    int n, expo;
    // 系数
    double coef;
    // 读取多项式A的项数
    scanf("%d", &n);
    // 多项式相加，指数相同的项进行系数相加
    while (n--) {
        scanf("%d %lf", &expo, &coef);
        mp[expo] = coef;
    }
    // 读取多项式B的项数
    scanf("%d", &n);
    while (n--) {
        scanf("%d %lf", &expo, &coef);
        // 指数相同，合并同类项
        if (mp[expo]) {
            mp[expo] += coef;
        } else {
            mp[expo] = coef;
        }
    }
    // 删除系数为0的多项式
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it -> second == 0) {
            mp.erase(it);
        }
    }
    printf("%d", mp.size());
    int i = 0;
    // map本身是字典序，如果从大到小遍历，需要倒着遍历
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        printf(" %d %.1f", it -> first, it -> second);
    }
    printf("\n");
    return 0;
}