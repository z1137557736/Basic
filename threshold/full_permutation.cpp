#include <cstdio>
#include <cmath>

// 数组长度
const int MAX = 10;
/* n 排列数{1,2,3,4}
 * p[] 当前排列
 * hashTable[] 保存排列状态
 */
int n = 8, count = 0, P[MAX], hashTable[MAX] = {0};

// 处理当前排列的第index号位
void fullPermutation(int index) {
    if (index == n + 1) { // 递归边界
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                // 判断x(列)以及y(行)的距离是否相等（正方形），或者说，判断是否在同一条对角线上
                if (abs(i - j) == abs(P[i] - P[j])) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            count++;
        }
        return;
    }
    for (int x = 1; x <= n; x++) { // 暴力枚举1~n
        // 如果x不在P排列中
        if (!hashTable[x]) {
            P[index] = x; // 令P的index位为x，即将x加入当前排列
            hashTable[x] = true; // 记录x已在排列P中
            fullPermutation(index + 1); // 处理排列的第index + 1位
            hashTable[x] = false; // 已处理完P[index]为x的子问题，还原状态
        }
    }
}

/**
 * 如果在到达递归边界之前，由于某些事实导致已经不需要往子问题递归，
 * 可以直接返回上一层（人为设置的到达递归边界），这种方法称为回溯法
 */
// N皇后，回溯法
void queenN(int index) {
    // 递归边界
    if (index == n + 1) {
        // 此时的N皇后摆放法不会冲突（合法方案），直接计数
        count++;
        return;
    }
    for (int x = 1; x <= n; x++) {
        // 当前x行已被皇后占用
        if (!hashTable[x]) {
            // 标识当前的皇后是否与之前的皇后冲突
            bool flag = true;
            for (int pre = 1; pre < index; pre++) { // 遍历之前的皇后
                // 第index列皇后的行号为x，第pre列皇后的行号为P[pre]
                if (abs(index - pre) == abs(x - P[pre])) { // 判断是否在同一角平分线上
                    flag = false;
                    break;
                }
            }
            // N皇后摆放方案错误，停止处理子问题
            if (flag) {
                P[index] = x;	// 令第index列皇后的行号为x
                hashTable[x] = true;	// 第x行已被皇后占用
                queenN(index + 1);	// 处理（index + 1）子问题
                hashTable[x] = false;	// 第x行恢复可用状态
            }
        }
    }
}

int queenN_main() {
    queenN(1);
    printf("%d皇后的摆放方案有：%d个", n, count);
    return 0;
}
