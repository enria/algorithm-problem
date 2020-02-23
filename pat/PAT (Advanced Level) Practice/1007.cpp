#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;
    int n[k];
    bool all_n = true;
    for (int i = 0; i < k; i++) {
        cin >> n[i];
        if (n[i] >= 0) {
            all_n = false;
        }
    }
    if (all_n) {
        printf("0 %d %d\n", n[0], n[k - 1]);
    } else {
        long max = 0;
        long cur_m = 0;
        int max_i = 0, max_j = 0;
        int cur_i = 0, cur_j = 0;
        while (cur_j < k) {
            cur_m += n[cur_j];
            if (cur_m < 0) {
                cur_i = cur_j + 1;
                cur_m = 0;
            } else {
                if (cur_m > max) {
                    max = cur_m;
                    max_i = cur_i;
                    max_j = cur_j;
                }
            }
            cur_j = cur_j + 1;
        }
        printf("%ld %d %d\n", max, n[max_i], n[max_j]);
    }
    return 0;
}