#include <cstdio>
#include <cmath>

const int PRIME_MAX = 101;
int prime[PRIME_MAX] = {}, primeNumber = 0;	// prime存放所有素数，primeNumber素数的总数量
bool p[PRIME_MAX] = {0};	// 素数表，复杂度为O(1)级别

// 判断是否是素数，复杂度为O(sqrt(n))
bool isPrime(int m) {
    if (m <= 1) {
        return false;
    }
    // m的开方数
    int q = (int) sqrt(m * 1.0);
    // 因为其因子必有一个小于等于q，一个大于等于q，所以只需判断从2~q的数即可
    for (int i = 2; i <= q; i++) {
        if (m % i == 0) {
            return false;
        }
    }
    return true;
}

// 埃氏筛法，复杂度为O(n*loglogn)
void findPrime() {
    for (int i = 2; i < PRIME_MAX; i++) {
        // 为素数时
        if (!p[i]) {
            prime[primeNumber++] = i;
            // 寻找素数i的倍数，并标记为合数
            for (int j = i * i; j < PRIME_MAX; j += i) {
                // true 为合数
                p[j] = true;
            }
        }
    }
}

// 生成1~100的素数表，复杂度为O(n*sqrt(n))
void findPrime2() {
    for (int i = 1; i < PRIME_MAX; i++) {
        if (isPrime(i)) {
            prime[primeNumber++] = i;
            // true 为素数
            p[i] = true;
        }
    }
}

// 恒等gcb(a, b) === gcb(b, a % b);  a = kb + r; 其中k为除数，r为余数
// 求最大公约数
int gcd(int a, int b) {
    int p = 0;
    printf("a = %d, b = %d, c = %d\n", a, b , p);
    while (b != 0) {
        p = a % b;
        a = b;
        b = p;
        printf("a = %d, b = %d, c = %d\n", a, b , p);
    }
    return a;
}

// 其中x，y为引用类型
int exGcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exGcd(b, a % b, x, y);
    // x = x2, y = y2
    int temp = x;
    x = y;	// 更新	x1 = y2
    y = temp - a / b * y; // 更新 y1 = x2 - (a/b) * y2
    return g;
}

// 递归计算最大公约数
int briefGcd(int a, int b) {
    return b ? briefGcd(b, a % b) : a;
}

// 返回n的阶乘中质因子p的数量O(logn)
// 求n的阶乘末尾0的个数，思考质因子 2 * 5 = 10时，会产生0，而质因子2的数量大于5，所以只需求5出现的次数即可
int caln(int n, int p) {
    int ans = 0;
    while (n) {
        ans += n / p;	// 累加 p / n^k
        n /= p;	// 相当于分式多除了一个p
    }
    return ans;
}

long long resC[67][67] = {};
// 求组合数，递归打表法
long long C(long long n, long long m) {
    // 递归边界
    printf("n = %d m = %d\n", n, m);
    if (m == 0 || m == n) return 1;
    if (resC[n][m] != 0) return resC[n][m];
    // 利用公式 C(n, m) = C(n - 1, m) + C(n - 1, m - 1)
    return resC[n][m] = C(n - 1, m) + C(n - 1, m - 1);
}

// 将组合数的整张表都计算出来
long long calC3(int n, int m) {
    const int MAX = 60;
    for (int i = 1; i <= MAX; i++) {
        resC[i][0] = resC[i][i] = 1;	// 边界为1
    }
    for (int i = 2; i <= MAX; i++) {
        // 利用C(n, m) == C(n, n - m)的性质
        for (int j = 1; j <= i / 2; j++) {
            resC[i][j] = resC[i - 1][j] + resC[i - 1][j - 1];	// C(n, m) = C(n - 1, m) + C(n - 1, m - 1)
            resC[i][i - j] = resC[i][j];	// C(n, n - m) = C(n, m)
        }
    }
    return resC[n][m];
}

// 组合数公式拆分，拆分如下，即i从1累加到m
// 分子 (n - m + 1)(n - m + 2)(n - m + 3) ···(n - m + m)
// 分母 (1*2*3 ···m)
// 可以分析出一共相乘m次，即复杂度为O(m)，
long long calC2(int n, int m) {
    int ans = 1;
    for (int i = 1; i <= m; i++) {
        // 每次累乘以上一个数再除以i（note：若先除i，除法无法取整）
        ans = ans * (n - m + i) / i;
    }
    return ans;
}

int fibonacciF[100] = {};
// 求斐波那契数列，求第n项
int f(int n) {
    // 递归边界
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (fibonacciF[n] != 0) return fibonacciF[n];
    // 从第三项开始
    return fibonacciF[n] = f(n - 1) + f(n - 2);
}

int main() {
    int x = 1, y = 0;
//	int g = exGcd(18, 12, x, y);
    printf("result = %d\n", calC3(6, 3));
//	printf("%d", isPrime(16));
    findPrime();
//	for (int i = 0; i < primeNumber; i++) {
//		printf("%d ", prime[i]);
//	}
//	int a, b;
//	printf("请输入两个数值：");
//	scanf("%d %d", &a, &b);
//	printf("a = %d, b = %d, 最大公约数为：%d\n", a, b, briefGcd(a, b));
    return 0;
}
