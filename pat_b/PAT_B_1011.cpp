#include <cstdio>

/**
 * 部分A+B
 * 给定：A = 3862767，Da = 6，则Pa = 66(即6出现次数的累加)
 */

int main() {
    long long A, B,
        Pa = 0, Pb = 0; // 新整数初始化
    int Da, Db;
    scanf("%lld %d %lld %d", &A, &Da, &B, &Db);
    // 取出整数A的所有数字，再对所有数字进行判断是否等于Da
    while (A > 0) {
        // 等式成立时，组成新整数
        if (A % 10 == Da) Pa = Pa * 10 + Da;
        A /= 10;
    }
    // 取出整数B的所有数字，再对所有数字进行判断是否等于Db
    while (B > 0) {
        // 等式成立时，组成新整数
        if (B % 10 == Db) Pb = Pb * 10 + Db;
        B /= 10;
    }
    printf("%lld", Pa + Pb);
}