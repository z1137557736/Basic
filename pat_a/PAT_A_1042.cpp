#include <cstdio>

/**
 * Shuffling Machine(机器洗牌)
 * 题意：假设纸牌为初始顺序(即未拆封时纸牌的顺序)，给定一副牌以及它洗牌的顺序，如[S3, H5, C1, D13, J2]与[4, 2, 5 ,3, 1]，洗牌后为[J2, H5, D13, S3, C1]
 * 如果再重复一次洗牌结果为：[C1, H5, S3, J2, D13]
 * 纸牌区间为[1, 54]
 *
 * 思路：利用两个数组，分为存放洗牌前A和洗牌后B的扑克牌。每一次重复洗牌时，需要洗牌后的扑克牌覆盖洗牌前的扑克牌
 */

const int MAX_SIZE = 55;

// 洗牌前的纸牌
int A[MAX_SIZE];
// 洗牌后的纸牌
int B[MAX_SIZE];
// 洗牌顺序
int P[MAX_SIZE];

// 标识纸牌的类别: Spade(黑) | Heart(红) | Club(梅) | Diamond(方块) | Joker(小丑)
char T[5] = {'S', 'H', 'C', 'D', 'J'};

int main() {
    // 重复次数
    int times;
    scanf("%d", &times);
    // 生成纸牌，区间为[1, 54]
    for (int i = 1; i < MAX_SIZE; i++) {
        A[i] = i;
    }
    for (int i = 1; i < MAX_SIZE; i++) {
        scanf("%d", &P[i]);
    }
    // 执行times次
    while (times--) {
        for (int i = 1; i < MAX_SIZE; i++) {
            // 将A[i] 移到 第P[i]个位置上
            B[P[i]] = A[i];
        }
        // 扑克牌的新顺序覆盖原顺序，便于下一次洗牌
        for (int i = 1; i < MAX_SIZE; i++) {
            A[i] = B[i];
        }
    }
    // 显然，扑克牌类型 = B[i] / 13，扑克牌 = B[i] % 13
    for (int i = 1; i < MAX_SIZE; i++) {
        // 方便处理
        B[i]--;
        printf("%c%d", T[B[i] / 13], B[i] % 13 + 1);
        // 输出空格
        if (i < MAX_SIZE - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}