#include "iostream"
#include "queue"

using namespace std;

int queue_main () {
    // 队列，先进先出；deque双向队列(首尾都可插入和删除的队列)
    queue<int> q;
    for (int i = 1; i <= 5; i++) {
        // 压入栈中
        q.push(i);
    }
    for (int i = 0; i < 3; i++) {
        // 出队
        q.pop();
    }
    // 获取队列的第一个对象和最后一个对象
    printf("%d %d\n", q.front(), q.back());
}
