#include <iostream>
#include <cstring>

using namespace std;

// 支持1000位的高精度整数运算
struct bign {
    int d[1000];
    int len;
    bool negative;
    // 构造函数初始化
    bign () {
        memset(d, 0, sizeof(d));
        len = 0;
        negative = false;
    }
};

// 消掉高位为0的数，保留一位0，如(str)00001 ==> (n)10000 ==> (n)1
bign wipeHigher(bign a) {
    while (a.len > 1 && a.d[a.len - 1] == 0) {
        a.len--;
    }
    // 为0时，将负号擦除
    if (a.len == 1 && a.d[0] == 0) {
        a.negative = false;
    }
    return a;
}

// 数组低位存低位，高位存高位
bign change(char str[]) {
    bign a;
    // 记录长度
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++) {
        int k = a.len - i - 1;
        if (k == 0 && str[k] == '-') {
            a.negative = true;
            a.len--;
        } else {
            // 字符 加减运算得到数值
            a.d[i] = str[k] - '0';	// '1' = 49, '0' = 48，'1' - '0' = 1;
        }
    }
    return wipeHigher(a);
}

// 打印高精度数
void print(bign a) {
    // 如果为负数
    if (a.negative) {
        printf("-");
    }
    // 从高位输出到低位
    for (int i = a.len - 1; i >= 0; i--) {
        printf("%d", a.d[i]);
    }
    printf("\n");
}

// 比较大小
// a > b return 1
// a < b return -1
// a == b return 0
int compare(bign a, bign b) {
    if (a.len > b.len) {
        return 1;
    } else if (a.len < b.len) {
        return -1;
    } else {
        // 从高位往低位比较
        for (int i = a.len - 1; i >= 0; i--) {
            if (a.d[i] > b.d[i]) {	// 高位a大于高位b，则a大
                return 1;
            } else if (a.d[i] < b.d[i]) {	// 高位a小于高位b，则b大
                return -1;
            }
        }
        // 完全相等，返回0
        return 0;
    }
}

/* 四则运算 */

// 只处理加法，不管正负
bign badd(bign a, bign b) {
    bign c;
    // 进位
    int carry = 0;
    // 相加完为止
    for (int i = 0; i < a.len || i < b.len; i++) {
        int num = a.d[i] + b.d[i] + carry;	// 两个对应位和进位相加
        c.d[c.len++] = num % 10; // 取个位数
        carry = num / 10; //  10位进位数
    }
    // 最后位相加超过10，直接将结果赋给最高位
    if (carry == 1) {
        c.d[c.len++] = carry;
    }
    // 正负以较大者a的符号为准
    c.negative = a.negative;
    return c;
}

// 只处理减法，不管正负，保证（a > b）
bign bminus(bign a, bign b) {
    bign c;
    for (int i = 0; i < a.len || i < b.len; i++) {
        // 如果不够减
        if (a.d[i] < b.d[i]) {
            // 高位减一, 低位加10
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    // 正负以较大者a的符号为准
    c.negative = a.negative;
    // 擦去高位为0的数
    return wipeHigher(c);
}

bign bjudge (bign a, bign b, bool add) {
    int flag = compare(a, b);
    // 当 a < b 时
    if (flag == -1) {
        // 当a < b 交换两个对象, 始终用大的减小的
        bign temp = b;
        b = a;
        a = temp;
    }
    if (!a.negative && !b.negative) {
        if (add) {
            return badd(a, b);	// 正加正，如 10+2
        } else {
            return bminus(a, b);	// 正减正，如 10-2
        }
    } else if (a.negative && b.negative) {
        if (add) {
            return badd(a, b);	// 负加负，如 -10+(-2) == -(10 + 2)
        } else {
            return bminus(a, b);	// 负减负，如 -10-(-2) == 2 - 10
        }
    } else if (!a.negative && b.negative) {
        if (add) {
            return bminus(a, b);	// 正加负，如 10+(-2) == 10 - 2
        } else {
            return badd(a, b);	// 正减负，如 10-(-2) == 10 + 2
        }
    } else {
        if (add) {
            return bminus(a, b);	// 负加正，如 -10+2 == 2 - 10
        } else {
            return badd(a, b);	// 负减正，如 -10-2 == -(10 + 2)
        }
    }
}

// 高精度加法
bign add(bign a, bign b) {
    return bjudge(a, b, 1);
}
// 高精度减法
bign sub(bign a, bign b) {
    return bjudge(a, b, 0);
}

// 高精度与低精度的乘法
bign multi(bign a, int b) {
    bign c;
    // 进位
    int carry = 0;
    for (int i = 0; i < a.len; i++) {
        // 加上进位数
        int num = a.d[i] * b + carry;
        // 取个位作为结果
        c.d[c.len++] = num % 10;
        // 高位部分作为新的进位
        carry = num / 10;
    }
    // 乘法的进位数可能不止一位，所以要循环添加高位数
    while (carry != 0) {
        // 取个位作为结果
        c.d[c.len++] = carry % 10;
        // 高位部分作为新的进位
        carry /= 10;
    }
    return c;
}

// 高精度的数除以低精度的数的商（带余数）
bign divide(bign a, int b, int& r) {
    bign c;
    c.len = a.len;
    for (int i = a.len - 1; i >= 0; i--) {
        r = r * 10 + a.d[i];
        if (r < b) {
            // 不够出，设0
            c.d[i] = 0;
        } else {
            // 取商
            c.d[i] = r / b;
            // 取余数
            r = r % b;
        }
    }
    return wipeHigher(c);
}

int main() {
//	char str1[5], str2[5];
//	scanf("%s%s", str1, str2);
//	print(add(change(str1), change(str2)));
    char str1[5];
    int num, r = 0;
    scanf("%s%d", str1, &num);
    print(divide(change(str1), num, r));
    printf("余数：%d", r);
    return 0;
}
