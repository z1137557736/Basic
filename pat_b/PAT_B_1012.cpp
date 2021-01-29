#include <cstdio>
#include <cstring>

/**
 * 数字分类
 */

int n;

int main() {
    scanf("%d", &n);
    // 存放A1 ~ A5的答案
    int A[6] = {};
    // A2用来标识交错求和
    int a2 = 0;
    // 记录A4的数量
    int a4Sum = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        // A1 = (整除5 && 偶数)的数之和
        if (num % 5 == 0 && num % 2 == 0) {
            A[1] += num;
        } else if (num % 5 == 1) {
            // A2 = (除5余1)交错求和(先加后减)
            if (a2++ % 2 == 0) {
                // 偶数执行加法
                A[2] += num;
            } else {
                // 奇数执行减法
                A[2] -= num;
            }
        } else if (num % 5 == 2) {
            // A3 = (除5余2)的个数
            A[3]++;
        } else if (num % 5 == 3) {
            // A4 = (除5余3)的数字的和
            A[4] += num;
            a4Sum++;
        } else if (num % 5 == 4) {
            // A5 = (除5余4)的最大的数
            // 大于则更新最大数
            if (num > A[5]) {
                A[5] = num;
            }
        }
    }
    // 数组下标从1开始
    for (int i = 1; i <= 5; i++) {
        if (A[i] == 0) {
            // 特判，因为A2交错求和后有可能会等于0，而只有当这类数字不存在才会输出N
            if (a2 > 0 && i == 2) {
                printf("0");
            } else {
                printf("N");
            }
        } else {
            // 等于4时，A4 为 (除5余3)的数字的平均数，精确到小数点后1位
            if (i == 4) {
                printf("%.1f", (double) A[4] / a4Sum);
            } else {
                printf("%d", A[i]);
            }
        }
        // 输出空格
        if (i < 5) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}