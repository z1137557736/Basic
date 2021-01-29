#include <cstdio>

/**
 * 一元多项式求导
 * 题意：指数递降方式输入多项式非零项系数和指数
 * 如f(x) = 3x^4 - 5x^2 + 6x - 2
 * 求导后 f'(x) = 12x^3 - 10x + 6
 */
const int MAX_SIZE = 1001;
int K[MAX_SIZE], E[MAX_SIZE];

int main() {
    // 系数 / 指数 / 第k个单项式
    int k, e, count = 0;
    // while ... eof
    while (scanf("%d %d", &k, &e) != EOF) {
        // 求导公式
        k = k * e--;
        if (k != 0) {
            K[count] = k;
            E[count++] = e;
        }
    }
    // 特判 零多项式
    if (count == 0) {
        printf("0 0");
    } else {
        for (int i = 0; i < count; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%d %d", K[i], E[i]);
        }
    }
    printf("\n");
    return 0;
}