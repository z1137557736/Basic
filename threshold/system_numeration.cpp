#include <cstdio>

using namespace std;

/**
 * 10进制转2进制（除基取余法）
 */
int dec2binary(int num) {
    // 存放二进制的数组
    int arr[31];
    // 记录二进制的位数
    int sum = 0;
    do {
        // 取余
        arr[sum++] = num % 2;
        // 除基
        num /= 2;
    } while (num != 0); // 商为0时，退出循环
    // 逆序输出
    for (int i = sum - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }
}

/**
 * p进制转10进制
*/
int to10(int x, int p) {
	int y = 0, product = 1;
	while (x != 0) {
		// x % 10 每次取最后一位数
		// product p的n次方
		y += (x % 10) * product;
		x /= 10;
		product = p * product;
	}
	return y;
}

// 字符串hash
int hashFunc(char S[], int len) {
	int id = 0;
	for (int i = 0; i < len; i++) {
		id = id * 26 + (S[i] - 'A'); // 26进制转10进制
	}
	return id;
}

// 求n的阶乘
int F(int n) {
	if (n == 1) return 1; // 递归边界
	else return F(n - 1) * n; // 没有到达递归边界时，继续递归
}

// 斐波那契数列的前n项和
int fibonacci(int n) {
	if (n == 0 || n == 1) return 1; // 递归边界
	else return fibonacci(n - 1) + fibonacci(n - 2); // 递归式
}

void test() {
	const int MAX = 100;
	char S[MAX][5], temp[5];
	int hashTable[26 * 26 * 26 + 10] = {};
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", S[i]);
		int id = hashFunc(S[i], 3);
		hashTable[id]++;
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", temp);
		int id = hashFunc(temp, 3);
		printf("%d\n", hashTable[id]);
	}
}

int main() {
	/*printf("%d\n", F(2));
	printf("%d\n", fibonacci(5));
	printf("%d\n", to10(111, 26));
	printf("%d %d", hashFunc("B", 1), hashFunc("BBB", 3));*/
//	printf("%d", hashFunc("BBB", 3));
    dec2binary(25);
    return 0;
}

