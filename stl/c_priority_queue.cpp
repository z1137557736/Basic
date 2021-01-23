#include "iostream"
#include "queue"

using namespace std;

struct fruit {
    string name;
    int price;
    fruit(string name, int price) {
        this -> name = name;
        this -> price = price;
    }
    // 从小往大排，所以价格越高优先级就越高
    // 使用常量引用类型(避免重复创建对象)来提高效率
    friend bool operator < (const fruit& f1, const fruit& f2) {
        return f1.price < f2.price;
    }
};

int priority_queue_main () {
    // 优先队列，底层使用堆实现的。在优先队列中，队首元素一定是队列中优先级最高的那个
    // 默认：数值越大优先级越高
    // priority_queue<char> queue;
    // 此定义方式等价于上方的定义方式
    priority_queue<int, vector<int>, less<>> queue;
    // vector是底层堆的一个数据承载，less为大顶堆(从小往大排)，greater表示小顶堆(从大往小排)
    queue.push('a');
    queue.push('z');
    queue.push('b');
    printf("%c\n", queue.top());
    fruit fruit1("香蕉", 2);
    fruit fruit2("苹果", 10);
    fruit fruit3("火龙果", 20);
    priority_queue<fruit> priorityQueue;
    priorityQueue.push(fruit1);
    priorityQueue.push(fruit3);
    priorityQueue.push(fruit2);
    cout << priorityQueue.top().name << ' ' << priorityQueue.top().price << endl;
}