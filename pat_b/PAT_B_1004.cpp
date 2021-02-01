#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
 * 成绩排名
 * 题意：给定n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号
 *
 * 思路：定义一个map，以成绩为key, 姓名和姓名为value，利用map自带的字典序；可以输出第一个和最后一个即可
 */

int n, m;

map<int, pair<string, string>> mp;

int main() {
    scanf("%d", &n);
    while (n--) {
        // 姓名 / 学号
        string name, stuCard;
        // 成绩
        int score;
        cin >> name >> stuCard >> score;
        // key value 映射
        mp[score] = make_pair(name, stuCard);
    }
    // 字典序是从小到大，所以最后一个是第一名
    cout << mp.rbegin() -> second.first << ' ' << mp.rbegin() -> second.second << endl;
    // 第一个为倒数第一
    cout << mp.begin() -> second.first << ' ' << mp.begin() -> second.second << endl;
    return 0;
}