#include <cstdio>
#include <queue>

using namespace std;

/**
 * 题意：给定树的后序遍历与中序遍历序列，求这棵树的层次遍历序列
 * Sample Input:
 * 7
 * 2 3 1 5 7 6 4
 * 1 2 3 4 5 6 7
 * Sample Output:
 * 4 1 6 3 5 7 2
 */

struct Node {
    // 数据域
    int data;
    // 左右子树
    Node* left;
    Node* right;
};

// 层次序列队列
queue<Node*> q;
const int MAX_SIZE = 50;
// 存放后序与中序序列的数组
int post[MAX_SIZE], in[MAX_SIZE];
// 结点数量
int n;


Node* create(int postL, int postR, int inL, int inR) {
    // 递归边界，当后序序列遍历完时
    if (postL > postR) {
        return NULL;
    }
    // 根节点
    Node* root = new Node;
    // 后序序列的根节点
    root -> data = post[postR];
    int k;
    for (k = inL; k < inR; k++) {
        // 找到中序序列的根结点，可以区分左右子树
        if (post[postR] == in[k]) {
            break;
        }
    }
    // 先得到左子树结点的数量
    int numLeft = k - inL;
    // 左子树的后序区间为[post, postL + numLeft - 1]，中序区间为[inL, k - 1]
    // 返回左子树的根节点，并赋值给root的左指针
    root -> left = create(postL, postL + numLeft - 1, inL, k - 1);
    // 右子树的后序区间为[postL + numLeft, postR - 1]，中序区间为[k + 1, inR]
    // 返回右子树的根节点，并赋值给root的右指针
    root -> right = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}

// 层次遍历
void layerOrder(Node* node) {
    q.push(node);
    int num = 1;
    while (!q.empty()) {
        // 取出队列的第一个元素
        Node* front = q.front();
        q.pop();
        printf("%d", front -> data);
        if (num++ < n) printf(" ");
        if (front -> left != NULL) {
            q.push(front -> left);
        }
        if (front -> right != NULL) {
            q.push(front -> right);
        }
    }
    printf("\n");
}

int main() {
    // 初始化
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    Node* root = create(0, n - 1, 0, n - 1);
    layerOrder(root);
    return 0;
}