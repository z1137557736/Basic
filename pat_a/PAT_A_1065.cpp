#include <cstdio>

/**
 * A+B and C (64bit)
 * 由于long long的数据范围是[-2^63, 2^63]
 * 且计算机组成原理中会指出，如果两个正数之和等千负数或是两个负数之和等千正数，那么就是溢出。
 */

int n;

int main() {
    long long A, B, C;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &A, &B, &C);
        if (A + B > C) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);
        }
    }
    return 0;
}