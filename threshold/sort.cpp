#include <cstdio>
#include <cmath>

// 选择排序
void selectionSort() {
    const int MAX = 6;
    int A[MAX] = {5, 2, 3, 1, 4, 6};

    for (int i = 0; i < MAX; i++) {
        int minIndex = i;
        for (int j = i + 1; j < MAX; j++) {
            // 寻找 i ~ MAX 中最小元素的下标
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }
        // 将 i 与 minIndex交换位置
        int temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }

    for (int i = 0; i < 6; i++) {
        printf("%d ", A[i]);
    }
}

// 插入排序，类似打跑得快给牌排序
void insertionSort() {
    const int MAX = 6;
    int A[MAX] = {5, 2, 3, 1, 4, 6};

    int current, preIndex;
    for (int i = 1; i < MAX; i++) {
        // 上一个元素下标
        preIndex = i - 1;
        // 先抽出当前值
        current = A[i];
        // 与前面的 i - 1 个元素进行比较，上一个元素大于当前元素
        while (preIndex >= 0 && A[preIndex] > current) {
            A[preIndex + 1] = A[preIndex--];
        }
        // 如果上一个元素比当前元素小，插入到上一个元素的前面，即preIndex + 1
        A[preIndex + 1] = current;
    }

    for (int i = 0; i < 6; i++) {
        printf("%d ", A[i]);
    }
}


// 将两个递增数组合并为一个（升序）数组，时间复杂度为 T(n+m)
// A[i] > B[j] C[index++] = B[j++]
// A[i] < B[j] C[index++] = A[i++]
int mergeArr(int A[], int B[], int C[], int n, int m) {
    // i指向A[0]，j指向B[0]，index指向C[0]
    int i = 0, j = 0, index = 0;
    // 当有一个数组下标到达边界时（防止下标越界），退出循环
    while (i < n && j < m) {
        // 元素小的将被排入C[index]（升序数组，从小排到大）
        if (A[i] > B[j]) {
            C[index++] = B[j++];
        } else {
            C[index++] = A[i++];
        }
    }
    // 将数组中剩余的元素填充到数组C中
    while (i < n) {
        C[index++] = A[i++];
    }
    while (j < m) {
        C[index++] = B[j++];
    }
    for (int i = 0; i < n + m; i++) {
        printf("%d ", C[i]);
    }
}

// 拆到最小子问题时，自下而上的迭代，最终将会变成两个有序数组的合并（每一次迭代都是如此）
// out-place 开辟了一个新的数组来辅助排序
void merge(int A[], int L1, int R1, int L2, int R2) {
    printf("L1:%d R1:%d L2:%d R2:%d\n", L1, R1, L2, R2);
    int i = L1, j = L2
    , temp[100] = {}, index = 0;
    // 只要有一个数组排完了就退出循环
    while (i <= R1 && j <= R2) {
        // 当A[i] == A[j] 时，先追加左子区间的元素，保证稳定性
        if (A[i] <= A[j]) {
            temp[index++] = A[i++];
        } else {
            temp[index++] = A[j++];
        }
    }
    // 将剩下的元素追加到数组temp中
    while (i <= R1) {
        temp[index++] = A[i++];
    }
    while (j <= R2) {
        temp[index++] = A[j++];
    }
    // 将数组temp的元素赋给数组A
    for (i = 0; i < index; i++) {
        A[L1 + i] = temp[i];
    }
}

// 使用分治的思想，自上而下的递归，先拆成最小子问题
void mergeSort(int A[], int left, int right) {
    // 递归边界
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, mid + 1, right);
    }
}

// 采用循环实现归并排序，n为数组的长度
void mergeSort2(int A[], int n) {
    // 当n为8时，step 2 4 8 16 32
    // 先分成最小子问题
    for (int step = 2; step / 2 < n; step *= 2) {
        // 再分别对每个子问题排序
        for (int i = 0; i <= n; i += step) {
            // 下列参数都需要取下标（原值是长度）所以都需要减 1

            // 当前每个子区间元素分别为 step / 2
            int mid = i + step / 2 - 1;
            // mid 不能超过 n
            if (mid + 1 <= n) {
                // R2最大下标为 n - 1
                merge(A, i, mid, mid + 1, fmin(i + step - 1, n - 1));
            }
        }
    }
}

//分割 左方元素小于temp，右方元素大于temp
int partition(int A[], int left, int right) {
    int temp = A[left];
    while (left < right) {
        // 两种情况退出循环，当left == right，或右方元素小于temp
        while (left < right && A[right] >= temp) {
            right--;	// 从右向左逼近
        }
        // 右方元素小于temp，移到左方
        A[left] = A[right];
        while (left < right && A[left] < temp) {
            left++; 	// 从左向右逼近
        }
        // 左方元素大于右方元素，将其移到右方
        A[right] = A[left];
    }
    // 此时 left == right，返回谁都行
    A[left] = temp;
    return left;
}

// 快速排序 当数组为有序时（最坏）复杂度为O(n2)，平均时间复杂度为O(nlogn)
int quickSort(int A[], int left, int right) {
    // （递归边界）当区间长度为0时，退出递归
    if (left < right) {
        // 将区间一分为二 A[left, right]
        int pos =  partition(A, left, right);
        // 对左子区间进行递归快速排序
        quickSort(A, left, pos - 1);
        // 对右子区间进行递归快速排序
        quickSort(A, pos + 1, right);
    }
}

// 随机选择（寻找第K大的数）
int randSelect(int A[], int left, int right, int K) {
    if (left >= right) {
        // 边界返回
        return A[right];
    }
    // 将数组A分为两个区间，[left, pos - 1]（左方元素小于A[pos]） 和 [pos + 1, right]（右方元素大于A[pos]）
    int pos = partition(A, left , right);
    // printf("pos:%d left:%d right:%d\n", pos, left, right);
    // 第M大的数
    int M = pos + 1;
    // 找到第K大的数
    if (K == M) {
        return A[pos];
    } else if (K < M) {
        // 当K小于M时，此时第K大的数在左区间
        return randSelect(A, left, pos - 1, K);
    } else {
        // 当K大于M时，此时第K大的数在右区间
        return randSelect(A, pos + 1, right, K);
    }
}

int	main() {
    /*int A[4] = {0, 1, 3, 4};
    int B[4] = {2, 3, 5, 8};
    int C[8] = {};
    mergeArr(A, B, C, 4, 4);*/
    int A[10] = {2, 3, 5, 8, 4, 7, 9, 10, 15, 14};
    // mergeSort(A, 0, 9);
    // mergeSort2(A, 10);
    // quickSort(A, 0, 9);
    printf("%d\n", randSelect(A, 0, 9, 7));

//	for (int i = 0; i < 10; i++) {
//		printf("%d ", A[i]);
//	}
}
