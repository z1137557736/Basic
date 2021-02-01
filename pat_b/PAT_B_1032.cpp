#include <cstdio>

/**
 * 挖掘机技术哪家强
 * 题意：给出n个人的学校编号与分数，统计出总得分最高的学校以及其分数
 *
 * 思路：定义一个数组A存放总分数，下标为学校编号
 */

const int MAX_SIZE = 100010;

int n;

int A[MAX_SIZE] = {};

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int id, score;
        scanf("%d %d", &id, &score);
        // 累加分数
        A[id] += score;
    }
    // 存放总分数最高的学校编号
    int max = 0;
    for (int i = 1; i <= n; ++i) {
        // 大于则更新
        if (A[i] > A[max]) {
            max = i;
        }
    }
    printf("%d %d\n", max, A[max]);
    return 0;
}