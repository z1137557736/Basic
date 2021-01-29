#include <cstdio>

/**
 * 程序运行时间
 * 给定C1，C2分别为时钟打点数(C2 > C1)，以及常数CLK_TCK，两个时钟打点数之差，再除以常数CLK_TCK就可以得到以秒为单位的运行时间。
 * 题目还单独要求，除以常数CLK_TCK需要四舍五入，考虑到CLK_TCK是100，可以转换为，如果(C2 - C1)的差的最后两位数大于50，则进一，反之弃之
 */

const int CLK_TCK = 100;

int main() {
    int C1, C2;
    scanf("%d %d", &C1, &C2);
    int ans = C2 - C1;
    // 开始四舍五入(此时ans的最后两个数是除以100后的小数)
    if (ans % CLK_TCK >= 50) {
        // 小数大于50，则进一
        ans = ans / CLK_TCK + 1;
    } else {
        ans = ans / CLK_TCK;
    }
    // 补2个0, ans为秒制度, | 取商 | 取余 | 取最后两位数
    printf("%02d:%02d:%02d\n", ans / 3600, ans % 3600 / 60, ans % 60);
    return 0;
}