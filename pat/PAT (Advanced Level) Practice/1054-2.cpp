#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define pii pair<int, int>

int main() {
    int n, m;
    cin >> n >> m;
    n = n * m;
    int num, cnt = 0;//TODO 找到数组中超过半数的数
    while (n--) {
        scanf("%d", &m);
        if (cnt == 0) {
            num = m;
            cnt = 1;
        } else if (num == m) {
            cnt++;
        } else {
            cnt--;
        }
    }
    cout << num << endl;
    return 0;
}