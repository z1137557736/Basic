#include <cstdio>
#include <map>

using namespace std;

/**
 * 考试座位号
 * 题意：给定准考证号、试机座位号、考试座位号。求试机座位号所对应的考试座位号
 *
 * 思路：定义一个map，以试机座位号为key, 准考证号和考试座位号为value
 */

int n, m;

map<int, pair<long long, int>> mp;

int main() {
    scanf("%d", &n);
    while (n--) {
        // 准考证号
        long long testNum;
        // 试机座位号、考试座位号
        int machineNum, seatNum;
        scanf("%lld%d%d", &testNum, &machineNum, &seatNum);
        // key value 映射
        mp[machineNum] = make_pair(testNum, seatNum);
    }
    scanf("%d", &m);
    while (m--) {
        int key;
        scanf("%d", &key);
        // 输出结果
        printf("%lld %d\n", mp[key].first, mp[key].second);
    }
    return 0;
}