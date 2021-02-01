#include <cstdio>
#include <map>

using namespace std;

/**
 * Product of Polynomials
 * 题意：关于多项式乘法
 *
 * 思路：temp用来存放多项式A。在读取多项式B时，每个单项式都可以与多项式A做乘积，最后合并同类项即可
 */

int n;
// 临时存放多项式A ｜ 存放多项式相乘结果
map<int, double> temp, mp;

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
        temp[expo] = coef;
    }
    // 读取多项式B的项数
    scanf("%d", &n);
    while (n--) {
        scanf("%d %lf", &expo, &coef);
        // 单项式跟多项式A相乘
        for (auto it = temp.begin(); it != temp.end(); it++) {
            // 同底数幂相乘，底数不变，指数相加
            int e = expo + it->first;
            // 系数相乘
            double c = coef * it->second;
            // 指数相同，合并同类项
            if (mp[e]) {
                mp[e] += c;
            } else {
                mp[e] = c;
            }
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