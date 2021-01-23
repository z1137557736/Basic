#include "iostream"
#include "stack"
#include "queue"
#include "string"
#include "map"

using namespace std;

// 存储表达式
struct node {
    double num; // 操作数
    char op;    //操作符
    bool  flag; // true 为操作数，false为操作符
};

// 字符串
string str;
// 存储运算符优先级
map<char, int> opMap;
// 运算符是从左向右计算，所以用队列存储操作数
queue<node> numQueue;
// 栈存储操作符
stack<node> opStack;

// step 1: 中缀转后缀
void change() {
    // 此处无自增，在循环体内自增
    for (int i = 0; i < str.length();) {
        node operation;
        // 判断是数值
        if (str[i] >= '0' && str[i] <= '9') {
            // 标记为操作数
            operation.flag = true;
            int num = 0;
            // note: 继续读！读取的不仅仅是个位数！(非负整数)
            while (str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + (str[i++] - '0');
            }
            // 字符转数值
            operation.num = num;
            // 入队
            numQueue.push(operation);
        } else { // 判断不为空串
            // 标记为操作符
            operation.flag = false;
            // 手动自增
            operation.op = str[i++];
            // 从左往右
            // 3 + 4 * 5
            // 3 4 5 * +
            // 首元素优先级高于当前元素，优先入操作数队列
            // 3 * 4 + 5
            // 3 4 * 5 +
            // 优先级相等时，也优先进入操作数队列
            // 3 / 4 * 5
            // 3 4 / 5 *
            // 操作符栈不为空
            while (!opStack.empty() && opMap[opStack.top().op] >= opMap[operation.op]) {
                // 只要栈中首元素的优先级，高于或等于当前操作符的优先级，就将首元素压入操作数队列中
                numQueue.push(opStack.top());
                // 去掉首元素
                opStack.pop();
            }
            // 直接压入操作栈中
            opStack.push(operation);
        }
    }
    // 将运算符都刷到操作数中
    while (!opStack.empty()) {
        // 将首元素操作符压入操作数栈中
        numQueue.push(opStack.top());
        // 去掉首元素
        opStack.pop();
    }
}

// step 2: 计算后缀表达式的值
double calculate() {
    // 操作数队列 全部出队
    while (!numQueue.empty()) {
        // 获取首元素
        node cur = numQueue.front();
        // 操作数 去掉首元素
        numQueue.pop();
        // 如果为运算符
        if (!cur.flag) {
            // 弹出两个数进行运算，并将结果压入栈中
            // 弹出第一个数
            double temp1 = opStack.top().num;
            // 出栈
            opStack.pop();
            // 弹出第二个数
            double temp2 = opStack.top().num;
            // 出栈
            opStack.pop();
            double ans = 0;
            // 前一个数 运算 后一个数
            if (cur.op == '+') ans = temp2 + temp1;
            else if (cur.op == '-') ans = temp2 - temp1;
            else if (cur.op == '*') ans = temp2 * temp1;
            else if (cur.op == '/') ans = temp2 / temp1;
            // 将结果压入栈中
            cur.num = ans;
            cur.flag = true;
            // 中缀表达式: 3 * 4 + 5
            // 后缀表达式：3 4 * 5 +
            // 12 5 +
            // 17
        }
        // 入栈
        opStack.push(cur);
    }
    return opStack.top().num;
}


// 简单计算器(后缀表达式实现)，一共分为两个步骤
// step 1: 中缀转后缀
// step 2: 计算后缀表达式的值
int main() {
    // 定义运算符优先级
    opMap['+'] = opMap['-'] = 0;
    opMap['*'] = opMap['/'] = 1;
    // 当读到0时退出循环
    while (getline(cin, str), str != "0") {
        // 循环去掉空格
        for (string::iterator it = str.begin(); it != str.end(); it++) {
            if (*it == ' ') str.erase(it);
        }
        // 操作符栈 初始化
        while (!opStack.empty()) opStack.pop();
        change();
        // 保留两位小数的浮点数
        printf("%.2f\n", calculate());
    }
    return 0;
}
