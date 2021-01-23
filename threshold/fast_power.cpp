#include <cstdio>
#include <ctime>

typedef long long LL;

// 普通求幂，时间复杂度为T(n)
LL normalPower(LL a, LL b, LL m) {
    LL ans = 1;
    for (int i = 0; i < b; i++) {
        ans = ans * a % m;
    }
    return ans % m;
}

// 快速幂，时间复杂度为T(log(n))
LL fastPower(LL base, LL power, LL m) {
    LL ans = 1;
    while (power > 0) {
        // 与运算符, 当前bit都为1时返回1，否则返回0
        // 5 [0 0 0 0 0 1 0 1]
        // 1 [0 0 0 0 0 0 0 1]
        // 6 [0 0 0 0 0 1 1 0]
        // 当power为奇数时，等价于 power % 2 != 0
        if (power & 1) {
            // 9^4 * 9^1
            // 其中 9^4 继续转换 81^2
            // 9^1计入结果中
            ans = (ans * base) % m;	// 指数为奇数时进行乘积计算
        }
        // 3^10 转换--> 9^5
        base = (base * base) % m;	// 底数则为原来的平方，保证原式值不变
        power >>= 1; // 等价于 power / 2（当power为奇数时会丢掉小数）
    }
    return ans % m;
}

int fastPower_main () {
    clock_t start, finish;
    start = clock();
//	printf("%lld\n", normalPower(2, 10, 100));
    printf("%lld\n", fastPower(2, 10, 100));
    finish = clock();
    // 秒数
    printf("the time cost is %f\n", double(finish - start) / CLOCKS_PER_SEC);
    return 0;
}
