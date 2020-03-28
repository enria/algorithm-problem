#include <iostream>
#include <map>

using namespace std;

int preOrder[50000], inOrder[50000];
map<int, int> inIndex;

int post_first(int preStart, int inStart, int len) {
    if (len == 1) {
        return preOrder[preStart];
    } else {
        int middle = inIndex[preOrder[preStart]];
        if (middle - inStart) {
            return post_first(preStart + 1, inStart, middle - inStart);
        } else {
            return post_first(preStart + 1, middle + 1, len - 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", preOrder + i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", inOrder + i);
        inIndex[inOrder[i]] = i;
    }
    printf("%d\n", post_first(0, 0, n));
    return 0;
}