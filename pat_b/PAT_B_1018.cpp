#include <cstdio>
#include <cstring>

/**
 * 锤子剪刀布
 * C代表“锤子”、J代表“剪刀”、B代表“布”，第一个字母代表甲方，第二个代表乙方
 * 求甲、乙各自的胜、平、负的次数；并分别给出甲、乙获胜次数最多的手势
 *
 * 思路：因为石头剪刀布为三种手势，所以判断胜负时有三种情况需要考虑
 */

int n;

// 分别存放甲(A)、乙(B)的胜 平 负
int A[3], B[3];
// 字典序存放甲乙获胜次数的手势，B C J
int countA[3], countB[3];
// 对应手势的下标(字典序)
char gesture[3] = {'B', 'C', 'J'};

// 记录各个手势胜利的次数
void countGesture(int count[], char gst) {
    switch (gst) {
        case 'B':
            count[0]++;
            break;
        case 'C':
            count[1]++;
            break;
        case 'J':
            count[2]++;
            break;
    }
}

void print(int G[]) {
    for (int i = 0; i < 3; i++) {
        printf("%d", G[i]);
        // 输出空格
        if (i < 2) {
            printf(" ");
        }
    }
}

// 获胜次数最多的手势的下标
int getMax(int count[]) {
    int u = 0;
    for (int i = 0; i < 3; ++i) {
        // 大于则更新
        if (count[i] > count[u]) {
            u = i;
        }
    }
    return u;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char gstA, gstB;
        // 加空格可以跳过换行符或者空格符
        scanf(" %c %c", &gstA, &gstB);
        // 平局
        if (gstA == gstB) {
            A[1]++;
            B[1]++;
        } else if ((gstA == 'C' && gstB == 'J') || (gstA == 'J' && gstB == 'B') || (gstA == 'B' && gstB == 'C')) {
            // 甲锤子 乙剪刀 || 甲剪刀 乙布 || 甲布 乙锤子
            A[0]++; // 甲方胜
            B[2]++; // 乙方输
            countGesture(countA, gstA);
        } else if ((gstB == 'C' && gstA == 'J') || (gstB == 'J' && gstA == 'B') || (gstB == 'B' && gstA == 'C')) {
            // 乙锤子 甲剪刀 || 乙剪刀 甲布 || 乙布 甲锤子
            B[0]++; // 乙方胜
            A[2]++; // 甲方输
            countGesture(countB, gstB);
        }
    }
    print(A);
    printf("\n");
    print(B);
    printf("\n");
    printf("%c %c\n", gesture[getMax(countA)], gesture[getMax(countB)]);
    return 0;
}