#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int miles[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", miles + i);
    }
    sort(miles, miles + n, [](int a, int b) -> bool { return a > b; });
    int m, e;
    for (int i = 0; i < n; i++) {
        if (i + 1 >= miles[i] - 1) {
            e = miles[i] - 1;
            break;
        }
    }
    printf("%d\n", e);
    return 0;
}