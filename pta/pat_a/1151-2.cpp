#include <iostream>
#include <map>
#include <vector>

using namespace std;

int inOrder[10010], preOrder[10010];
map<int, int> inIndex;

int m, n;

int find_parent(int a, int b) {
    int aIn = inIndex[a], bIn = inIndex[b];
    int inEnd = n - 1, inStart = 0, preStart = 0;
    while (inEnd >= inStart) {
        int rootIn = inIndex[preOrder[preStart]];
        //等于0，说明a和b其中一个为父亲。小于0，说明分布在两侧。
        if ((aIn - rootIn) * (bIn - rootIn) <= 0) {
            return inOrder[rootIn];
        }
        if (aIn < rootIn) {
            preStart++;
            inEnd = rootIn - 1;
        } else {
            preStart += rootIn - inStart + 1;
            inStart = rootIn + 1;
        }
    }
    return 0;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", inOrder + i);
        inIndex[inOrder[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", preOrder + i);
    }
    for (int i = 0, v1, v2; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        if (!inIndex.count(v1) || !inIndex.count(v2)) {
            if (!inIndex.count(v1) && !inIndex.count(v2)) {
                printf("ERROR: %d and %d are not found.\n", v1, v2);
            } else {
                printf("ERROR: %d is not found.\n",
                       inIndex.count(v1) ? v2 : v1);
            }
        } else {
            int anc = find_parent(v1, v2);
            if (anc == v1 || anc == v2) {
                printf("%d is an ancestor of %d.\n", anc, anc == v1 ? v2 : v1);
            } else {
                printf("LCA of %d and %d is %d.\n", v1, v2, anc);
            }
        }
    }
    return 0;
}