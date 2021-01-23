#include <cstdio>
#include <vector>

using namespace std;

/**
 * 题意：给定一串序列，要求判断此序列是BST或镜像BST的先序序列，如果是返回“YES”并输出其后序序列，反之则返回“NO”
 */

// 定义BST的结构
struct Node {
    // 数据域
    int data;
    // 左右子树指针域
    Node* left;
    Node* right;

    // 带参数的构造方法
    Node(int data) {
        this -> data = data;
        left = right = NULL;
    }
};

/**
 * 插入结点
 * @param root 根节点（引用类型）
 * @param x 被插入的值
 */
void insert(Node* &root, int x) {
    // 指针为空时，插入到此结点
    if (root == NULL) {
        root = new Node(x);
        return;
    }
    // x小于data时，往左子树插入结点
    if (x < root -> data) {
        insert(root -> left, x);
    } else {
        // x大于等于data时，往右子树插入结点
        insert(root -> right, x);
    }
}

/**
 * 镜像递归插入
 */
void insertMirror(Node* &root, int x) {
    // 指针为空时，插入到此结点
    if (root == NULL) {
        root = new Node(x);
        return;
    }
    // x大于等于data时，往左子树插入结点
    if (x >= root -> data) {
        insertMirror(root -> left, x);
    } else {
        insertMirror(root -> right, x);
    }
}

/**
 * 创建BST
 * @param v 一串序列
 * @param mirror 是否创建镜像树
 * @return
 */
Node* create(vector<int> v, bool mirror) {
    Node* root = NULL;
    // 创建镜像BST
    if (mirror) {
        // 指针循环
        for (auto it = v.begin(); it != v.end(); it++) {
            insertMirror(root, *it);
        }
    } else {    // 创建BST
        // 普通循环
        for (int i = 0; i < v.size(); i++) {
            insert(root, v[i]);
        }
    }
    return root;
}

int n;
vector<int> iv, // iv 存放输入序列
    pre_bv,   // 存放BST先序遍历的序列
    pre_mbv,  // 存放Mirror Image BST先序遍历的序列
    post_v;  // 存放BST后序遍历的序列(用于输出)

// 先序遍历(根左右)
void preorder(Node* root, vector<int> &v) {
    // 到达递归边界
    if (root == NULL) {
        // 到达空树，退出递归
        return;
    }
    v.push_back(root -> data);
    preorder(root -> left, v);
    preorder(root -> right, v);
}

// 后序遍历(左右根)
void postoder(Node* root, vector<int> &v) {
    // 到达递归边界
    if (root == NULL) {
        // 到达空树，退出递归
        return;
    }
    postoder(root -> left, v);
    postoder(root -> right, v);
    v.push_back(root -> data);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        iv.push_back(temp);
    }
    Node* bst = create(iv, false);
    Node* bst_mirror = create(iv, true);
    // 生成bst前序序列
    preorder(bst, pre_bv);
    // 生成mirror bst前序序列
    preorder(bst_mirror, pre_mbv);
    // 输入序列等于BST的先序序列
    if (iv == pre_bv) {
        postoder(bst, post_v);
    } else if (iv == pre_mbv) { // 输入序列等于Mirror image of the BST的先序序列
        postoder(bst_mirror, post_v);
    }
    // 后序序列不为空
    if (!post_v.empty()) {
        printf("YES\n");
        for (int i = 0; i < post_v.size(); i++) {
            printf("%d", post_v[i]);
            if (i < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
}