#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
};

int main() {
    int n;
    cin >> n;
    node head;
    node* cur = &head;
    for (int i = 0; i < n; i++) {
        node *nd=(node*)malloc(sizeof(node));
        nd->data = i;
        cur->next = nd;
        cur = cur->next;
    }
    cur = head.next;

    while (cur) {
        cout << cur->data << endl;
        cur = cur->next;
    }

    return 0;
}