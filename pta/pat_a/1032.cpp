#include <string.h>
#include <iostream>

using namespace std;

int nextp[100000];

int len(int start) {
    int l = 0;
    while (start > -1) {
        l++;
        start = nextp[start];
    }
    return l;
}

int main() {
    memset(nextp, -1, sizeof(int) * 100000);
    int s1, s2, n;
    cin >> s1 >> s2 >> n;
    for (int i = 0; i < n; i++) {
        int index, _next;
        char c;
        scanf("%d %c %d", &index, &c, &_next);
        nextp[index] = _next;
    }
    int l1 = len(s1), l2 = len(s2);
    if (l1 > l2) {
        for (int i = 0; i < l1 - l2; i++) {
            s1 = nextp[s1];
        }
    } else {
        for (int i = 0; i < l2 - l1; i++) {
            s2 = nextp[s2];
        }
    }

    while (s1 > -1 && s2 > -1) {
        if (s1 == s2) {
            printf("%05d\n", s1);
            return 0;
        }
        s1 = nextp[s1];
        s2 = nextp[s2];
    }
    printf("-1\n");
    return 0;
}