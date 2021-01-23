#include <cstdio>

/**
 * BST(Binary Search Tree) 二叉查找树；定义：对于每一个根节点，其左子树的数据域小于根节点的数据域，右子树的数据域大于根节点的数据域
 * 性质：
 * 当对二叉查找树进行中序遍历时，遍历的结果是有序的，其本身利用了：左 < 根 < 右 的特性
 */
struct Node {
    // 数据域
    int data;
    // 左右子树的指针域
    Node* left;
    Node* right;

    // 定义带参数的构造函数
    Node(int data) {
        this -> data = data;
        left = right = NULL;
    }
};

/**
 * 查询结点
 * @param root 根节点
 * @param x 查询的值
 */
void search(Node* root, int x) {
    if (root == NULL) {
        return;
    }
    if (x == root -> data) {
        printf("%d\n", root -> data);
        return;
    } else if (x < root -> data) {
        // 往左子树找
        search(root -> left, x);
    } else {
        // 往右子树找
        search(root -> right, x);
    }
}

/**
 * 插入结点
 * @param root 利用引用对象插入结点
 * @param x 被插入的值
 */
void insert(Node* &root, int x) {
    // 这里判断的是指针为空
    if (root == NULL) {
        root = new Node(x);
        return;
    }
    // 说明当前结点已存在，直接返回
    if (x == root -> data) {
        return;
    } else if (x < root -> data) {
        // 小于根结点，往左子树插入结点
        insert(root -> left, x);
    } else {
        // 大于根结点，往右子树插入结点
        insert(root -> right, x);
    }
}

/**
 * 寻找左子树中的最大结点(前驱)
 * @param root 根节点
 * @return 返回左子树中最大结点
 */
Node* findMax(Node* root) {
    while (root -> right != NULL) {
        // 不断往右，直接没有右子结点
        root = root -> right;
    }
    return root;
}

/**
 * 寻找右子树中的最小结点(后继)
 * @param root 根节点
 * @return 返回右子树中最小结点
 */
Node* findMin(Node* root) {
    while (root -> left != NULL) {
        // 不断往左，直接没有左子结点
        root = root -> left;
    }
    return root;
}

/**
 * 删除结点<br/>
 * 优化点：
 * 1. 删除前驱或后继结点时，不一定要再次递归删除；假设前驱结点为Pre，其Pre的父结点为S
 * 如Pre肯定没有右子树，且当Pre没有左子树时，Pre为叶子结点，可直接删除；
 * 若Pre有左子树时，可以将S的右子树指向Pre的左子树(覆盖Pre)；后继结点同理可证。
 * 2. 总是优先删除前驱(或后继)结点会导致树的高度不平衡；
 * 方法一：可以前驱(或后继)结点交替删除。
 * 方法二：记录树的高度，总是优先在高度较高的子树上删除结点。
 * @param root 根节点(引用对象)
 * @param x 被删除的值
 */
void deleteNode(Node* &root, int x) {
    // 结点为空，直接返回
    if (root == NULL) {
        return;
    } else if (x == root -> data) {
        // 直到当前结点为叶子结点，直接删除
        if (root -> left == NULL && root -> right == NULL) {
            // 引用对象删除，标记为NULL
            root = NULL;
            // 并释放内存
            delete root;
        } else if (root -> left != NULL) {  // 左子树不为空，先删除左子树
            // 从左子树挑选最大结点(前驱)
            Node* node = findMax(root -> left);
            // 将前驱结点覆盖root结点
            root -> data = node -> data;
            // 删除前驱结点(因为前驱结点可能也是非叶子结点，不可直接删除；所以往root的左子树继续删除)
            deleteNode(root -> left, node -> data);
        } else {
            // 从右子树中挑选最小结点(后继)
            Node* node = findMin(root -> right);
            // 将后继结点覆盖root节点
            root -> data = node -> data;
            // 删除后继结点(因为后继结点可能也是非叶子结点，不可直接删除；所有往root的右子树继续删除)
            deleteNode(root -> right, node -> data);
        }
    } else if (x < root -> data) {
        // x小于当前结点的值，往左子树删除
        deleteNode(root -> left, x);
    } else {
        // x大于当前结点的值，往右子树删除
        deleteNode(root -> right, x);
    }
}

/**
 * 创建树
 * @param arr 结点值
 * @param n 结点数量
 * @return 返回树的根结点
 */
Node* create(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(root, arr[i]);
    }
    return root;
}

int main() {

}

