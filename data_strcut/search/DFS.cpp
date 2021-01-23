#include <cstdio>

/**
 * DFS depth first search(深度优先搜索，一般使用栈实现，枚举所有可能性)
 * note: 遍历顺序形成的结构类似于二叉树
 * 两个概念1. 岔道口 2. 死胡同
 * 利用递归(其本质就是栈)进行实现，其中递归式就是岔道口，而递归边界则是死胡同
 * 选择若干件物品放入背包，使其价格之和最大，且体积不能超过V
 */

const int MAX_SIZE = 30;
// w[i] 重量 c[i] 价格
int w[MAX_SIZE], c[MAX_SIZE];
// n 物品数量 V 背包容量 maxValue 最大价值
int n, V, maxValue = 0;

/**
 * index 为当前处理物品的编号 sumW和sumC分别为总容量和总价格
 * 复杂度为o(2^n) 因为每件物品都有选或不选这两种选择的
 * 此方法效率低下，但是可以优化
 */
void DFS(int index, int sumW, int sumC) {
    // 已经完成对n件物品的选择(死胡同)，到达递归边界
    if (index == n) {
        // 当前容量未超过总容量且当前价格高于最大价值时，更新最大价值
        if (sumW <= V && sumC > maxValue) {
            maxValue = sumC;
        }
        // 退出此次循环
        return;
    }
    // 有两种选择(岔道口)，选择当前物品或不选择当前物品(装或不装入背包)

    // 不挑选第index件装入背包中
    DFS(index + 1, sumW, sumC);
    // 挑选第index件装入背包中
    DFS(index + 1, sumW + w[index], sumC + c[index]);
}

// 背包问题改良版的DFS
void improve_DFS(int index, int sumW, int sumC) {
    // 已完成对n件物品的挑选，退出循环(死胡同)
    if (index == n) {
        return;
    }
    improve_DFS(index + 1, sumW, sumC);
    // 如果总容量 + 当前物品的容量 <= 背包容量(提前预判死胡同，避免不必要的循环，也被称为剪枝)
    if (sumW + w[index] <= V) {
        // 当前价格之和大于最大价格时，更新最大价格
        if (sumC + c[index] > maxValue) {
            maxValue = sumC + c[index];
        }
        // 将其装入背包，并进行下一件物品的挑选(分岔口)
        improve_DFS(index + 1, sumW + w[index], sumC + c[index]);
    }
}

int main() {
    // 物品数量与背包容量
    scanf("%d %d", &n, &V);
    // 填充物品数量
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    // 填充物品价格
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    improve_DFS(0, 0, 0);
    printf("%d", maxValue);
}