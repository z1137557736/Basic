#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * Shortest Distance(最短距离)
 * 题意：给定N个结点，N个结点围成了一个圈，再给定各点之间的距离。最后，判断各点之间的最短距离
 * 结点区间：[1, N]
 *
 * 思路：直接暴力遍历整个圈来获取两点之间的距离，会使得其运行超时。
 * 这里采用dis[i]和sum，其中dis[i] = V[1] ~ V[i]的距离，而sum为整个圈的距离
 * 而求解两点之间的最短距离可以化为 min(dis[i], sum - dis[i])
 */

const int MAX_SIZE = 10;

// dis[i] = V[1] ~ V[i + 1]的距离 / 整个圈的总距离
int dis[MAX_SIZE] = {}, sum = 0;

// 点距
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int d;
        scanf("%d", &d);
        // 整个圈的总距离
        sum += d;
        // dis[i] = V[1] ~ V[i + 1]的距离
        dis[i] = sum;
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        int left, right;
        scanf("%d %d", &left, &right);
        // 保证 left < right
        if (left > right) {
            swap(left, right);
        }
        // 顺时针两点之间的距离
        int t = dis[right - 1] - dis[left - 1];
        printf("%d\n", min(t, sum - t));
    }
    return 0;
}