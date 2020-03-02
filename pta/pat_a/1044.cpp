#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ds[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", ds + i);
    }
    int next = 1, sum = 0, min = -1;
    bool exact = false;
    for (int i = 1; i <= n; i++) {
        for (int j = next; j <= n; j++) {
            sum += ds[j];
            if (sum == m) {
                printf("%d-%d\n", i, j);
                next = j + 1;
                sum = sum - ds[i];
                exact = true;
                break;
            } else if (sum > m) {
                if (min == -1 || sum < min) min = sum;
                if (i == j) {
                    sum = 0;
                    next = j + 1;
                } else {
                    sum = sum - ds[i] - ds[j];
                    next = j;
                }
                break;
            }
        }
    }
    if (!exact) {
        next = 1, sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = next; j <= n; j++) {
                sum += ds[j];
                if (sum == min) {
                    printf("%d-%d\n", i, j);
                    next = j + 1;
                    sum = sum - ds[i];
                    break;
                } else if (sum > min) {
                    if (i == j) {
                        sum = 0;
                        next = j + 1;
                    } else {
                        sum = sum - ds[i] - ds[j];
                        next = j;
                    }
                    break;
                }
            }
        }
    }

    return 0;
}