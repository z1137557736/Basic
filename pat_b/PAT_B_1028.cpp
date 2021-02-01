#include <cstdio>

/**
 * 人口普查
 * 题意：找出镇上最年长和最年轻的人。
 * 给出n个人的出生日期，找出其中大于等于1814/09/06和小于等于2014/09/06的出生日期的人数，以及其中最年长和最年轻的人
 *
 * 思路：定义person结构，用来存放姓名和出生日期。用eldest存放最年长的人，youngest存放最年轻的人，left和right限制区间的范围
 */

struct Person {
    // 姓名
    char name[20];
    // 出生日期
    int yy, mm, dd;
    Person() {

    }
    Person(int yy, int mm, int dd) {
        this -> yy = yy;
        this -> mm = mm;
        this -> dd = dd;
    }
} eldest(2014, 9, 6)
, youngest(1814, 9, 6)
, left(1814, 9, 6)
, right(2014, 9, 6), temp;

int n;

// a <= b 返回true，否则返回false
bool lessEqu(Person a, Person b) {
    // 当年月不相等时，可以直接比较大小；否则需要进行对日子比较大小
    if (a.yy != b.yy) return a.yy <= b.yy;
    else if (a.mm != b.mm) return a.mm <= b.mm;
    else return a.dd <= b.dd;
}

// a >= b 返回true，否则返回false
bool greaterEqu(Person a, Person b) {
    // 当年月不相等时，可以直接比较大小；否则需要进行对日子比较大小
    if (a.yy != b.yy) return a.yy >= b.yy;
    else if (a.mm != b.mm) return a.mm >= b.mm;
    else return a.dd >= b.dd;
}

int main() {
    scanf("%d", &n);
    int count = 0;
    while (n--) {
        scanf("%s %d/%d/%d", temp.name, &temp.yy, &temp.mm, &temp.dd);
        // temp 属于 [left, right]这个区间
        if (greaterEqu(temp, left) && lessEqu(temp, right)) {
            count++;
            // Note：下面两个条件可能会同时成立
            // 出生日期小于最年长者，则更新
            if (lessEqu(temp, eldest)) eldest = temp;
            // 出生日期大于最年轻者，则更新
            if (greaterEqu(temp, youngest)) youngest = temp;
        }
    }
    printf("%d", count);
    if (count != 0) {
        printf(" %s %s\n", eldest.name, youngest.name);
    }
    return 0;
}