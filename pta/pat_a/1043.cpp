#include <iostream>

using namespace std;

int dat[1001];

struct Btn {
    int data;
    Btn *left, *right;
};

bool is_bst = true;
int rt = 0;  // 0：未初始化，1：正，-1：反

void build_tree(Btn *root, int start, int end) {
    if (!is_bst) {
        return;
    }
    if (end - start == 0) {
        return;
    }
    root->data = dat[start];
    if (end - start == 1) {
        return;
    }

    if (rt == 0) {
        int split_index = -1;
        if (dat[start + 1] >= dat[start]) {
            for (int i = start + 1; i < end; i++) {
                if (split_index != -1 && dat[i] >= dat[start]) {
                    is_bst = false;
                    return;
                }
                if (dat[i] < dat[start]) {
                    if (split_index == -1) {
                        split_index = i;
                    }
                }
            }
            if (split_index != -1) {
                rt = -1;
                root->left = (Btn *)malloc(sizeof(Btn));
                root->right = (Btn *)malloc(sizeof(Btn));
                build_tree(root->left, start + 1, split_index);
                build_tree(root->right, split_index, end);
            } else {
                Btn *only_child = (Btn *)malloc(
                    sizeof(Btn));  //还不知道是在左边还是在右边，往下探
                build_tree(only_child, start + 1, end);
                if (rt == 1) {
                    root->right = only_child;
                } else {
                    root->left = only_child;
                }
            }
        } else {  //后一个值比第一个值小
            int split_index = -1;
            for (int i = start + 1; i < end; i++) {
                if (split_index != -1 && dat[i] < dat[start]) {
                    is_bst = false;
                    return;
                }
                if (dat[i] >= dat[start]) {
                    if (split_index == -1) {
                        split_index = i;
                    }
                }
            }
            if (split_index != -1) {
                rt = 1;
                root->left = (Btn *)malloc(sizeof(Btn));
                root->right = (Btn *)malloc(sizeof(Btn));
                build_tree(root->left, start + 1, split_index);
                build_tree(root->right, split_index, end);
            } else {
                Btn *only_child = (Btn *)malloc(
                    sizeof(Btn));  //还不知道是在左边还是在右边，往下探
                build_tree(only_child, start + 1, end);
                if (rt == 1) {
                    root->left = only_child;
                } else {
                    root->right = only_child;
                }
            }
        }

    } else {
        int split_index = -1;
        if (rt == 1) {
            for (int i = start + 1; i < end; i++) {
                if (split_index != -1 && dat[i] < dat[start]) {
                    is_bst = false;
                    return;
                }
                if (dat[i] >= dat[start]) {
                    split_index = i;
                }
            }
        } else {
            for (int i = start + 1; i < end; i++) {
                if (split_index != -1 && dat[i] >= dat[start]) {
                    is_bst = false;
                    return;
                }
                if (dat[i] < dat[start]) {
                    split_index = i;
                }
            }
        }
        if (split_index == -1) {
            root->left = (Btn *)malloc(sizeof(Btn));
            build_tree(root->left, start + 1, end);
        } else {
            root->left = (Btn *)malloc(sizeof(Btn));
            root->right = (Btn *)malloc(sizeof(Btn));
            build_tree(root->left, start + 1, split_index);
            build_tree(root->right, split_index, end);
        }
    }
}
bool first = true;
void postOrder(Btn *root) {
    if (!root) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    if (first) {
        printf("%d", root->data);
        first = false;
    } else {
        printf(" %d", root->data);
    }
}

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        scanf("%d", dat + i);
    }
    Btn *root = (Btn *)malloc(sizeof(Btn));
    build_tree(root, 0, k);
    if (is_bst) {
        printf("YES\n");
        postOrder(root);
        printf("\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
