#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 题意：给定一棵树和若干结点的权值，求所有根节点到叶子结点的路径，使得每条路径的上结点的权值之和等于给定的常数S。如果有多条，则按对应的结点非增序(降序)输出
 */
const int MAX_SIZE = 105;
// 树的基本结构
struct Node {
    // 数据域(权值)
    int weight;
    // 指针域(将数组的下标视为指针)
    vector<int> child;
} node[MAX_SIZE];   // 结点数组

// 降序排序
bool cmp(int a, int b) {
    return node[a].weight > node[b].weight;
}

// n为树的结点数量，m为非叶子结点的数量，S为特定的常数S
int n, m, S;

// 保存从根节点到叶子结点的路径
int PATH[MAX_SIZE];

/**
 * 使用深度优先搜索，获取权值之和等于S的从根节点到叶子结点的路径
 * @param child 子结点地址(下标)
 * @param count 当前已访问的结点个数
 * @param sum 权值
 */
void DFS(int index, int count, int sum) {
    // 当前sum超过给定的S，直接返回
    if (sum > S) return;
    // 权值之和等于S && 当前node[index]结点为叶子结点
    if (sum == S && node[index].child.empty()) {
        for (int i = 0; i < count; i++) {
            printf("%d", node[PATH[i]].weight);
            if (i < count - 1) {
                printf(" ");
            }
        }
        printf("\n");
        return;
    }
    // 枚举所有的子结点
    for (int i = 0; i < node[index].child.size(); i++) {
        // 第i个叶子结点的地址
        int child = node[index].child[i];
        // 记录子结点的路径
        PATH[count] = child;
        // 继续搜索其叶子结点
        DFS(child, count + 1, sum + node[child].weight);
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &S);
    for (int i = 0; i < n; i++) {
        scanf("%d", &node[i].weight);
    }
    // id为父结点；k为子结点的数量；child为子结点权值
    int id, k, child;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            // 添加子结点
            node[id].child.push_back(child);
        }
        // 降序排序(保证后续权值之和相等时，按权值从大到小的输出)
        sort(node[id].child.begin(), node[id].child.end(), cmp);
    }
    // 路径的第一个结点设置为0结点
    PATH[0] = 0;
    DFS(0, 1, node[0].weight);
}