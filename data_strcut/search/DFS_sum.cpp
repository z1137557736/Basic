#include <cstdio>
#include <vector>

using namespace std;

/**
 * 给定n个整数，从中选择出k个数，使得k个数之和等于一个给定的整数x；如果有多种方案，则选择它们平方和大的数
 * 分岔口：对于每个数都有选与不选两种选择
 * 死胡同：1)已完成对n的数的选择；2)选择的个数不能超过k，且其之和大于给定的整数x
 */

const int MAX_SIZE = 30;
int n, k, x;
// 最大平方和
int maxSumSqu = 0;
int s[MAX_SIZE];
vector<int> ans, temp;

/**
 * DFS最优方案的挑选
 * @param index 当前数的下标
 * @param selectedK 已挑选的数量
 * @param sum k个数的和
 * @param sumSqu k个数的平方和
 */
void DFS(int index, int selectedK, int sum, int sumSqu) {
    // 找到k个数和为x，且平方和大于最大平方和
    if (selectedK == k && sum == x && sumSqu > maxSumSqu) {
        // 更新最大平方和
        maxSumSqu = sumSqu;
        // 更新最优方案
        ans = temp;
        return;
    }
    // 已完成对n个数的选择 || 已选择的数大于k || k个数之和大于给定的x
    if (index == n || selectedK > k || sum > x) {
        return;
    }
    // 当进入index号分支时，将s[index]加入temp中
    temp.push_back(s[index]);
    // 选择index号数，并累加和与平方
    DFS(index + 1, selectedK + 1, sum + s[index], sumSqu + s[index] * s[index]);
    // 当这个分支走完时，就把它从temp中去掉(后进先出)
    temp.pop_back();
    // 不选择index号数
    DFS(index + 1, selectedK, sum, sumSqu);
}

int main() {
    scanf("%d %d %d", &n , &k, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    DFS(0, 0, 0, 0);
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    printf("%d", maxSumSqu);
}