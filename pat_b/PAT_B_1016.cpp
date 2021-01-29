#include <cstdio>

/**
 * A+B 和 C
 * 给定区间[-2^31, 2^31]内的三个整数A、B和C，请判断A + B是否大于C
 * 思路：需要知道int的数值范围为[-2^32, 2^32 - 1]，当两个int相加时显然会超过int的数值范围
 * 所以，这里使用long long来存储A、B和C
 */

int T;

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        long long A, B, C;
        scanf("%lld %lld %lld", &A, &B, &C);
        if (A + B > C) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);
        }
    }
}