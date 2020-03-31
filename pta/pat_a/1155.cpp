#include <iostream>
#include <vector>

using namespace std;

// 2:MAX 1 :MIN -1: NOT
int isHeap = 0, n;

void judge_heap(vector<int> nodes) {
    int curHeap = 0;
    for (int i = 0; i < nodes.size(); i++) {
        printf("%d", nodes[i]);
        printf(i == nodes.size() - 1 ? "\n" : " ");
        if (i > 0 && curHeap >= 0) {
            if (curHeap) {
                if (curHeap == 2 && nodes[i] > nodes[i - 1]) curHeap = -1;
                if (curHeap == 1 && nodes[i] < nodes[i - 1]) curHeap = -1;
            } else {
                if (nodes[i] > nodes[i - 1]) {
                    curHeap = 1;
                } else if (nodes[i] < nodes[i - 1]) {
                    curHeap = 2;
                }
            }
        }
    }
    if (!isHeap) {
        isHeap = curHeap;
    } else if (isHeap != -1) {
        if (curHeap == -1) isHeap = -1;
        if (curHeap == 2 && isHeap == 1) isHeap = -1;
        if (curHeap == 1 && isHeap == 2) isHeap = -1;
    }
}

vector<int> levelOrder;
void right_first(int root, vector<int> parents) {
    parents.push_back(levelOrder[root]);
    if (root * 2 + 2 < n) {
        right_first(root * 2 + 2, parents);
    }
    if (root * 2 + 1 < n) {
        right_first(root * 2 + 1, parents);
    } else {
        judge_heap(parents);
    }
}

int main() {
    cin >> n;
    levelOrder.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &levelOrder[i]);
    }
    vector<int> output;
    right_first(0, output);
    switch (isHeap) {
        case -1:
            printf("Not Heap\n");
            break;
        case 1:
            printf("Min Heap\n");
            break;
        case 2:
            printf("Max Heap\n");
            break;
        default:
            break;
    }
    return 0;
}
