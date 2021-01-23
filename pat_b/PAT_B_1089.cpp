#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 狼人杀-简单版
 * 题意：在5名玩家中，由两个人是狼人，两个人说假话(一个狼人和一个好人)，求扮演狼人的玩家是谁
 * 思路：重点是先找狼人
 */
// 记录每个人说的话(1~n)，即玩家编号，正号为好人，负号为坏人
int n;

int main() {
    scanf("%d", &n);
    // 先指定vector的大小，才能直接使用&V[i]去接受值
    vector<int> V(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &V[i]);
    // 从小到大枚举，保证输出最小序列解
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            // lie 为说谎人数的集合 / a为狼人好人集合，其中1为好人，-1为狼人
            vector<int> lie, a(n + 1, 1);
            // 先假设 a[i] 与 a[j] 为狼人，其余人都为好人
            a[i] = a[j] = -1;
            // 找到说谎的人
            for (int k = 1; k <= n; k++) {
                // 判断玩家k的是否说谎(如果和假设的身份有冲突，则为说谎者)
                if (a[abs(V[k])] * V[k] < 0) {
                    lie.push_back(k);
                }
            }
            // 有两人说假话 && 且是一个狼人与一个好人
            if (lie.size() == 2 &&  a[lie[0]] + a[lie[1]] == 0) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}