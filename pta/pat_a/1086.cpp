#include <iostream>
#include <vector>

using namespace std;

int stack_des[70], n;

struct Node {
    int data;
    Node *left, *right;
};

Node *buildTree(int start, int end) {  //左闭右开
    if (end - start < 1) {
        return NULL;
    } else {
        Node *root = (Node *)malloc(sizeof(Node));
        root->data = stack_des[start];
        int pop = end - 1, stack = 0;
        for (int i = start + 1; i < end; i++) {
            if (stack_des[i] == 0) {
                stack--;
            } else {
                stack++;
            }
            if (stack == -1) {
                pop = i;
                break;
            }
        }
        root->left = buildTree(start + 1, pop);
        root->right = buildTree(pop + 1, end);
        return root;
    }
}
// TODO 传入Vector，看是传引用，还是传值
vector<int> post;
void postOrder(Node *root) {
    if (!root) {
        return;
    } else {
        postOrder(root->left);
        postOrder(root->right);
        post.push_back(root->data);
    }
}

int main() {
    cin >> n;
    string _des;
    for (int i = 0, _in; i < n * 2; i++) {
        cin >> _des;
        if ("Push" == _des) {
            scanf("%d", stack_des + i);
        } else {
            stack_des[i] = 0;
        }
    }
    Node *root = buildTree(0, n * 2);
    postOrder(root);
    for (int i = 0; i < post.size(); i++) {
        printf("%d", post[i]);
        printf(i == post.size() - 1 ? "\n" : " ");
    }
    return 0;
}