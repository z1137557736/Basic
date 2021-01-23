#include "iostream"
#include "stack"

using namespace std;

int main() {
    // 栈，后进先出
    stack<int> st;
    for (int i = 1; i <= 5; i++) {
        st.push(i);
    }
    // 返回最后一个被添加的元素(5)
    printf("%d", st.top());
    return 0;
}