#include <cstdio>

/**
 * 害死人不偿命的(3n+1)猜想
 * 卡拉兹(Callatz)猜想：对于任何一个正整数n，如果它是偶数，那么就将它砍掉一半；如果是奇数，那么把(3n + 1)砍掉一半。
 */

int n;

int main() {
    scanf("%d", &n);
    int ans = 0;
    while (n != 1) {
        // 为偶数时除半
        if (n % 2 == 0) {
            n /= 2;
        } else {
            // 为奇数时 n = (3n + 1) / 2
            n = (3 * n + 1) / 2;
        }
        ans++;
    }
    printf("%d", ans);
}