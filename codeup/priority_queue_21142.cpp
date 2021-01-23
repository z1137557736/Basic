#include <cstdio>
#include <queue>

using namespace std;

/**
 * 哈夫曼树：带权路径最小的树被称为哈夫曼树（又称为最优二叉树）
 * 合并果子
 * 本质上是求哈夫曼树的带权路径长度
 * 带权路径长度：所有叶子结点的带权路径长度之和 or 非叶子结点权值之和
 * 叶子节点的带权路径长度：根结点到叶子节点所经过的边数 * 叶子节点的权值（可以理解为叶子节点被累加了多少次）
 */

// 定义小顶堆（优先队列）
priority_queue<long long, vector<long long>, greater<>> q;

int n;

int main() {
    // 结果
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long temp;
        scanf("%lld", &temp);
        // 加入小顶堆
        q.push(temp);
    }
    // 当只剩下一个结点时，退出循环
    while (q.size() > 1) {
        // 获取两个最小的结点
        long long s1 = q.top();
        q.pop();
        long long s2 = q.top();
        q.pop();
        long long sum = s1 + s2;
        // 累加非叶子节点的权值
        ans += sum;
        // 将非叶子结点加入队列
        q.push(sum);
    }
    printf("%lld\n", ans);
    return 0;
}