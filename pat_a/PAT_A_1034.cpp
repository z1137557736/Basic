#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * Head of a Gang
 * 题意：给定一个通话时长的清单，找到通话总时长高于阈值K的帮派，以及这个帮派中通话时间最长的人（即帮派中点权最高的人）
 * 只需构造两人通话时长的图（无向图）
 */

// 通话记录不超过1000，则通话人数不超过2000
const int MAX_SIZE = 2005;

int n,  // 为通话时长的数量
    k,  // 通话时长的阈值
    vertex = 0;  // 给姓名分配的顶点(可以充当顶点数量)

// 数据的承载：邻接矩阵
int G[MAX_SIZE][MAX_SIZE];
// string 映射 int
map<string, int> str2intMap;
// int 映射 string
map<int, string> int2strMap;
// 记录犯罪团伙的首领名字以及帮派人数
map<string, int> Gangs;
// 记录顶点的权重
int weight[MAX_SIZE] = {};
// 记录顶点是否被访问
bool vis[MAX_SIZE] = {false};

// 采用深度优先搜索
void DFS(int v, int &head, int &totalWeight, int &totalMembers) {
    // 标识为已访问
    vis[v] = true;
    // 帮派人数+1
    totalMembers++;
    // 点权最大的为标记为首领
    if (weight[v] > weight[head]) {
        head = v;
    }
    // 枚举 与顶点v邻接的顶点
    for (int i = 0; i < vertex; i++) {
        // 边权大于0
        if (G[v][i] > 0) {
            // 累加边权
            totalWeight += G[v][i];
            // 累加完边权后，将无向边删除，避免重复累加
            G[v][i] = G[i][v] = 0;
            // 顶点t未被访问过
            if (!vis[i]) {
                DFS(i, head, totalWeight, totalMembers);
            }
        }
    }
}

// 遍历图
void traverG() {
    for (int i = 0; i < vertex; i++) {
        int head = i,   // 头领的编号
            totalWeight = 0,    // 计算边权得到的通话总时长
            totalMembers = 0;   // 当前的帮派人数
        // 枚举每一个未被访问过的顶点
        if (!vis[i]) {
            DFS(i, head, totalWeight, totalMembers);
            // 通话时长超过阈值 且 帮派成员人数大于2
            if (totalWeight > k && totalMembers > 2) {
                // 帮派首领的姓名以及帮派人数
                Gangs[int2strMap[head]] = totalMembers;
            }
        }
    }
}

// 给名字分配的顶点并返回顶点
int putAndGet(const string& name) {
    // name不存在
    if (str2intMap.find(name) == str2intMap.end()) {
        // 姓名 -> 编号
        str2intMap[name] = vertex;
        // 编号 -> 姓名
        int2strMap[vertex++] = name;
    }
    return str2intMap[name];
}

int main() {
    cin >> n >> k;
    // 边权
    int w;
    // 字符串无法直接用scanf读取，所以采用cin读取
    string s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> w;
        // 取s1对应的顶点
        int v1 = putAndGet(s1);
        // 取s2对应的顶点
        int v2 = putAndGet(s2);
        // 累加点权
        weight[v1] += w;
        weight[v2] += w;
        // 顶点v1 到 顶点v2 的累加边权为w
        G[v1][v2] += w;
        G[v2][v1] += w;
    }
    traverG();
    cout << Gangs.size() << endl;
    if (!Gangs.empty()) {
        // 利用map的字典序排序输出
        for (auto it = Gangs.begin(); it != Gangs.end(); it++) {
            // 指针对象取值法(point -> property)
            cout << it -> first << " " << it -> second << endl;
        }
    }
}