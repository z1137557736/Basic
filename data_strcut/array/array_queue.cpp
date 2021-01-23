/**
 * 简单的用数组实现了队列(先进先出)
 */
struct array_queue {
    // 数据的承载
    int q[10] = {};
    // 指向首元素的下标(默认-1)
    int front = -1;
    // 指向尾元素的下标(默认-1)
    int rear = -1;

    void clear() {
        front = rear = -1;
    }

    int size() {
        return rear + 1;
    }

    int empty() {
        // 相等时返回true
        return front == rear;
    }

    // 尾元素加1
    void push(int n) {
        q[++rear] = n;
    }

    // 出队，先进先出
    void pop() {
        front++;
    }

    // 取首元素
    int get_front() {
        return q[front + 1];
    }

    // 取尾元素
    int get_rear() {
        return q[rear];
    }
};