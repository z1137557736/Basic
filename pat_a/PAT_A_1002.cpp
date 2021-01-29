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
    /*scanf("%d", &n);
    while (n--) {
        scanf("%d %lf", &expo, &coef);
        // 存在即累加
        if (mp[expo]) {
            mp[expo] += coef;
        } else {
            mp[expo] = coef;
        }
    }*/
    printf("%d ", mp.size());
    // map本身是字典序，如果从大到小遍历，需要倒着遍历
    for (auto it = mp.begin(); it != mp.end(); it++) {
        printf("%d %.1f\n", it -> first, it -> second);
    }
    return 0;
}