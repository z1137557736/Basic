#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * 用数组现实大顶堆（完全二叉树）
 */

const int MAX_SIZE = 100;

// heap为堆，n为元素个数
int heap[MAX_SIZE], n = 10;

/**
 * 对heap数组在[low, high]范围内进行向下调整
 * 从下到上，从右到左调整
 * @param low 待调整结点的数组下标
 * @param high 一般为堆的最后一个元素的数组下标
 */
void downAdjust(int low, int high) {
    // 获取low的左子结点
    int child = low * 2;
    // 结点存在
    while (child <= high) {
        // 右子节点存在 && 右子结点大于左子结点
        if (child + 1 <= high && heap[child + 1] > heap[child]) {
            // 将child改为右子结点的下标
            child++;
        }
        // 根结点 小于 最大子结点
        if (heap[low] < heap[child]) {
            // 交换位置
            swap(heap[low], heap[child]);
            // low 指向 child，为待调整结点
            low = child;
            // child 指向 左子结点
            child = child * 2;
        } else {
            // 根结点 大于 其子结点，直接退出循环
            break;
        }
    }
}

/**
 * 向上调整
 * 若子结点大于父结点，则交换其位置，否则退出循环
 * @param low 一般为1，堆的第一个元素
 * @param high 待调整的结点
 */
void upAdjust(int low, int high) {
    // 找到父结点
    int father = high / 2;
    while (father >= low) {
        // 如果父结点的权值 小于 low的权值
        if (heap[father] < heap[low]) {
            // 交换父亲与待调整结点
            swap(heap[father], heap[high]);
            // 保证high为待调整结点，father为父结点
            high = father;
            father /= 2;
        } else {
            // 反之，父结点大于low待调整结点，退出循环
            break;
        }
    }
}

// 删除堆顶元素
void deleteTop() {
    // 用最后一个元素覆盖第一个元素
    // 想一想为什么要用最后一个元素替换第一个元素：因为又要删除堆顶元素又要保证完全二叉树的结构不能被破坏
    heap[1] = heap[n--];
    // 向下调整堆顶元素
    downAdjust(1, n);
}

// 建树
void createHeap() {
    // 对于每一个非叶子结点进行向下调整
    for (int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);
    }
}

// 入堆
void insert(int x) {
    heap[++n] = x;  // 元素个数+1，且将数组末尾赋值为x
    upAdjust(1, n); // 向上调整
}

// 堆排序(增序排序)，利用堆顶为最大元素的特性实现
void sortHeap(int high) {
    if (high > 1) {
        // 每次将堆顶与堆区间[1, high]中的最后一个元素交换
        swap(heap[1], heap[high]);
        // 调整堆区间为[1, high - 1]
        high--;
        // 堆顶向下调整，保证堆顶永远是最大元素
        downAdjust(1, high);
        sortHeap(high);
    }
}

int main() {
    for (int i = 1; i <= n; i++) {
        scanf("%d", &heap[i]);
    }
    createHeap();
    sortHeap(n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
}