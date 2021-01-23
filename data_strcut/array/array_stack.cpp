/**
 * 简单的用数组实现了栈(后进先出)
 */
struct array_stack {
    // 数据的承载(临时)
    int obj[10] = {};
    // 首元素的下标
    int top = -1;

    void clear() {
        top = -1;
    }

    int size() {
        return top + 1;
    }

    bool empty() {
        return top == -1;
    }

    // 入栈
    void push(int d) {
        obj[++top] = d;
    }

    // 出栈
    void pop() {
        top--;
    }

    // 获取首元素
    int get_top() {
        return obj[top];
    }
};