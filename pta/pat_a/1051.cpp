#include <iostream>
#include <stack>

using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    m++;  //放入0，省得判断为空了
    for (int i = 0; i < k; i++) {
        stack<int> dat;
        bool fail = false;
        int cur = 1, needpop;  // cur还没进stack
        dat.push(0);
        for (int j = 0; j < n; j++) {
            scanf("%d", &needpop);
            if (fail) {
                continue;
            }
            if (dat.top() < needpop) {
                for (int j = cur; j < needpop; j++) {
                    dat.push(j);
                    if (dat.size() == m) {
                        fail = true;
                        break;
                    }
                }
                cur = needpop + 1;
            } else if (dat.top() == needpop) {
                dat.pop();
            } else {
                fail = true;
            }
        }
        printf(fail ? "NO\n" : "YES\n");
    }
    return 0;
}