#include <iostream>

using namespace std;

int suffix(string s1, string s2) {
    int len = 0;
    for (int i = s1.length() - 1, j = s2.length() - 1; i >= 0 && j >= 0;
         i--, j--, len++) {
        if (s1.at(i) != s2.at(j)) {
            break;
        }
    }
    return len;
}

int main() {
    int n;
    scanf("%d\n", &n);
    string last, cur;
    getline(cin, last);
    int len = -1;
    for (int i = 0; i < n-1; i++) {
        getline(cin, cur);
        int suflen = suffix(last, cur);
        if (len == -1 || suflen < len) {
            len = suflen;
        }
        last = cur;
    }
    if (len == 0) {
        printf("nai\n");
    } else {
        printf("%s\n", last.c_str() + (last.size() - len));
    }
    return 0;
}