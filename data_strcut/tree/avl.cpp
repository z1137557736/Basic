#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

/**
 *  平衡二叉树；避免BST（二叉查找树）变成一个链表
 *  定义：保证每次元素插入和删除后仍是O(log n)的级别
 */

struct Node {
    // 树的数据域和高度
    int data, height;
    // 左右子树的指针域
    Node *left, *right;

    // 带参构造方法
    Node(int data) {
        this -> data = data;
        // 结点的初始高度为1
        height = 1;
        // 左右子树指针为NULL
        left = right = NULL;
    }
};

// 获取结点的高度
int getHeight(Node* root) {
    if (root == NULL) return 0;
    return root -> height;
}

// 计算平衡因子
int getBalanceFactor(Node* root) {
    // 左子树高度减去右子树高度
    return getHeight(root -> left) - getHeight(root -> right);
}

// 更新结点的高度
void updateHeight(Node* root) {
    // root -> height = max(左子树的高度，右子树的高度) + 1
    root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
}

/**
 * 左旋(left rotation)
 * note: 取权值最大的结点当根结点 (temp > temp -> left > root)，确保temp的左子树都比temp小
 * @param root 引用类型
 */
void L(Node* &root) {
    // 定义temp为root的右子树
    Node* temp = root -> right; // 先取出root的右子树
    root -> right = temp -> left;   // root的右子树指向temp的左子树
    temp -> left = root;    // temp的左子树指向root
    updateHeight(root); // 更新root结点的高度
    updateHeight(temp); // 更新temp结点的高度
    root = temp;    // 将temp更新为根结点
}

/**
 * 右转(right rotation)
 * note: 取权值最小的当根结点 (temp < temp -> right < root)，确保右转后temp的右子树都比temp大
 * @param root 引用类型
 */
void R(Node* &root) {
    // 定义temp为root的左子树
    Node* temp = root -> left;  // 先取出root的左子树
    root -> left = temp -> right;   // root的左子树指向temp为的右子树
    temp -> right = root;   // temp的右子树指向root
    updateHeight(root); // 更新root结点的高度
    updateHeight(temp); // 更新temp结点的高度
    root = temp;    // 将temp更新为根结点
}

/**
 * 插入结点：从下往上判断结点是否失衡，并设置根结点的高度
 * LL型: BF(root) == 2 && BF(root -> left) == 1；右转root
 * LR型: BF(root) == 2 && BF(root -> left) == -1；左转root -> left, 右转root
 * RR型: BF(root) == -2 && BF(root -> right) == -1；左转root
 * RL型: BF(root) == -2 && BF(root -> right) == 1；右转root -> right，左转root
 * @param root 根结点
 * @param x 被插入的值
 */
void insert(Node* &root, int x) {
    // 指针为空，插入结点
    if (root == NULL) {
        root = new Node(x);
        return;
    }
    // 结点已存在
    if (x == root -> data) {
        return;
    } else if (x < root -> data) {
        // 小于时，则往左子树插入结点
        insert(root -> left, x);
        // 更新root结点的高度
        updateHeight(root);
        // 当左子树高度 - 右子树高度 == 2，超出平衡因子
        if (getBalanceFactor(root) == 2) {
            // LL型
            if (getBalanceFactor(root -> left) == 1) {
                R(root);
            } else if (getBalanceFactor(root -> left) == -1) {  // LR型
                L(root -> left);
                R(root);
            }
        }
    } else {
        // 反之，则往右子树插入结点
        insert(root -> right, x);
        // 更新root结点的高度
        updateHeight(root);
        // 当左子树高度 - 右子树高度 == -2，超出平衡因子
        if (getBalanceFactor(root) == -2) {
            // RR型
            if (getBalanceFactor(root -> right) == -1) {
                L(root);
            } else if (getBalanceFactor(root -> right) == 1) {  // RL型
                R(root -> right);
                L(root);
            }
        }
    }
}

// 递归查找结点中数据域为x的结点
Node* search(Node* root, int x) {
    if (root == NULL) {
        return NULL;
    }
    // 找到数据域为x的结点，直接返回
    if (x == root -> data) {
        return root;
    } else if (x < root -> data) {
        // x 小于当前结点数据域，往左子树搜索
        search(root -> left, x);
    } else {
        // 反之，往右子树搜索
        search(root -> right, x);
    }
}

// 创建树
Node* create(vector<int> v) {
    Node* root = NULL;
    for (int i = 0; i < v.size(); i++) {
        insert(root, v[i]);
    }
    return root;
}

// 中序遍历(左根右)
void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root -> left);
    printf("%d ", root -> data);
    inOrder(root -> right);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    Node* root = create(v);
    inOrder(root);
}