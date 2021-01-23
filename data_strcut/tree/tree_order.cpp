#include <cstdio>
#include <queue>

using namespace std;

/**
 * 树的遍历：根结点，左子树，右子树；左子树一定在右子树前面
 * preorder(先序遍历)：根左右
 * inorder(中序遍历)：左根右
 * postorder(后序遍历)：左右根
 */
// 树节点
struct Node {
    // 数据域
    int data;
    // 左子树
    Node* left;
    // 右子树
    Node* right;

    // 构造函数
    Node(int data) {
        this -> data = data;
        // 指针定义为null
        left = right = NULL;
    }
};

// 插入结点，左小右大；note：此时node必须加引用标志&
void insert(Node* &root, int data) {
    // 如果指针为空
    if (root == NULL) {
        // 创建对象
        root = new Node(data);
        // 退出循环
        return;
    }
    // data 小于 根节点的数据域，插入到左子树
    if (data < root -> data) {
        insert(root -> left, data);
    } else {
        // 大于根结点的数据，插入到右子树
        insert(root -> right, data);
    }
}

/** 使用DFS(深度优先搜索)实现 **/
// 先序遍历(根左右)
void preorder(Node* root) {
    // 递归边界
    if (root == NULL) {
        // 到达空树，退出递归
        return;
    }
    // 根节点最先输出
    printf("%d ", root -> data);
    preorder(root -> left);
    preorder(root -> right);
}

// 中序遍历(左根右)
void inorder(Node* root) {
    // 递归边界
    if (root == NULL) {
        // 到达空树，退出递归
        return;
    }
    inorder(root -> left);
    // 根节点在中间输出
    printf("%d ", root -> data);
    inorder(root -> right);
}

// 后序遍历(左右根)
void postorder(Node* root) {
    // 递归边界
    if (root == NULL) {
        // 到达空树，退出递归
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    // 根节点最后输出
    printf("%d ", root -> data);
}

/** 使用BFS(广度优先搜索)实现 **/
void layerOrder(Node* root) {
    queue<Node*> q;
    // 将根结点入栈；note：这里入栈的是Node*(指针型)，所以修改原元素也会影响栈内中的元素
    q.push(root);
    // 修改原元素时会影响栈内元素的数据
    // root -> data = 9;
    while (!q.empty()) {
        // 弹出首元素
        Node* top = q.front();
        printf("%d ", top -> data);
        q.pop();
        // 左子树不为空时，压入栈
        if (top -> left != NULL) {
            q.push(top -> left);
        }
        // 右子树不为空时，压入栈
        if (top -> right != NULL) {
            q.push(top -> right);
        }
    }
}


int main() {
    // 定义根结点，指针为空
    Node* node = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        insert(node, temp);
    }
    preorder(node);
    printf("\n");
    inorder(node);
    printf("\n");
    postorder(node);
    printf("\n");
    layerOrder(node);
    return 0;
}