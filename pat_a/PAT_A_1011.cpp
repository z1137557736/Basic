#include <cstdio>

using namespace std;

/**
 * World Cup Betting
 * 题意：给出三行数据，代表三场比赛。每行有三个浮点数，找出各行的最大浮点数，然后根据给定的公式计算最大收益
 */

int n = 3;
char sign[3] = {'W', 'T', 'L'};
double ans[3] = {};

int main() {
    for (int i = 0; i < n; i++) {
        // 存放最大浮点数的下标及其最大值
        int u = 0;
        double m = 0.0;
        for (int j = 0; j < n; j++) {
            double temp;
            scanf("%lf", &temp);
            if (temp > m) {
                u = j;
                m = temp;
            }
        }
        // 存放各行最大值
        ans[i] = m;
        // 各行最大值的符号
        printf("%c ", sign[u]);
    }
    // 根据给定公式计算利益最大值
    printf("%.2f\n", (ans[0] * ans[1] * ans[2] * 0.65 - 1) * 2);
    return 0;
}