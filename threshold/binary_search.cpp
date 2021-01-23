#include <cstdio>
#include <cmath>

// epsilon 邻域
const double eps = 1e-5;
const double PI = acos(-1);

// 经典二分
int binarySearch(int A[], int left, int right, int x) {
    while (left <= right) { // 如果left > right，此时无法形成闭区间
        int mid = (left + right) / 2; // 取中中点数下标
        if (A[mid] == x) {
            return mid; // 找到则返回
        } else if (x < A[mid]) { // 如果x小于中点数
            right = mid - 1; // 往左子区间寻找[left, mid - 1]
        } else { // 如果x大于中点数
            left = mid + 1;	//  往右子区间寻找[mid + 1, right]
        }
    }
    // if not found
    return -1;
}

// 返回第一个大于等于x的元素
// 二分上下界为闭区间[left, right], 初始值为[0, n]
// 下界是0，上界是n而不是n - 1，因为总是要返回一个大于等于x的数，且这个数可能比数组的所有元素都大
// 那么假设这个数存在，即上界为n。
int lowBound(int A[], int left, int right, int x) {
    while (left < right) {	// 当left == right时，已经找到了第一个大于等于x的数
        int mid = (left + right) / 2;
        if (A[mid] >= x) {
            right = mid; //	因为寻找大于等于x的数，所以无需减1（等于也满足题意）
        } else {
            // left用来逼近right
            left = mid + 1;
        }
    }
    // 因为最后为left == right，所以既可以返回left，也可以返回right
    return left;
}

// 返回第一个大于x的元素
int upBound(int A[], int left, int right, int x) {
    while (left < right) {
        int mid = (left + right) / 2;
        // 除了将大于等于换成大于，其它与lowBound一致
        if (A[mid] > x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// f(x) = x2
double f2(double x) {
    return x * x;
}

// 求t开方后的近似值
double calSquare(double left, double right, int t) {
    double mid;
    while (right - left > eps) {
        mid = (left + right) / 2;
        // 大于往左子区间寻找[left, mid]
        if (f2(mid) > t) {
            right = mid;
        } else {
            // 小于往右子区间寻找[mid, right]
            left = mid;
        }
    }
    return mid;
}

// f(h) = r（装水问题的函数）
double fCircle(double R, double h) {
    double alpha = 2 * acos((R - h) / R);
    // 直线L的长度
    double L2 = 2 * (cos(asin((R - h) / R)) * R);
    double L = 2 * sqrt(R * R - (R - h) * (R - h));
    //  半圆面积
    double S2 = PI * R * R / 2;
    // 圆弧弧度制面积 - 三角形面积
    double S1 = (alpha * R * R / 2) - (L * (R - h) / 2);
    return S1 / S2;
}

// 装水问题
double chargeWater(double R, double r) {
    double left = 0, right = R, mid;
    while (right - left > eps) {
        mid = (left + right) / 2;
        // 函数f(x)是增函数
        if (fCircle(R, mid) > r) {
            right = mid;	// 一个往左子区间[left, mid]向左逼近
        } else {
            left = mid;		// 一个往右子区间[mid, right]向右逼近
        }
    }
    return mid;	// 此时cid是水面高度的近似值
}

int binarySearch_main() {
    int A[10] = {1, 3, 3, 3, 3, 9, 10, 13, 15, 16};
//	printf("%d %d %d", binarySearch(A, 0, 9, 9), lowBound(A, 0, 10, 9), upBound(A, 0, 10, 16));
//	printf("%.10lf\n", calSquare(1, 100, 2));
    printf("%.4f\n", chargeWater(10.5, 0.4));
    return 0;
}