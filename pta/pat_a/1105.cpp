#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int *nums, **result, N;

void fiil_nums(int idx, int off, int m, int n) {
    if (m <= 0 || n <= 0) {
        return;
    }
    for (int i = off; i < off + n; i++) {
        result[off][i] = nums[idx++];
    }
    for (int i = 1; i < m; i++) {
        result[off + i][off + n - 1] = nums[idx++];
    }
    for (int i = off + n - 2; i >= off; i--) {
        result[off + m - 1][i] = nums[idx++];
    }
    //这里只有一列的话，会出问题
    for (int i = off + m - 2; i > off && n > 1; i--) {
        result[i][off] = nums[idx++];
    }
    fiil_nums(idx, off + 1, m - 2, n - 2);
}

int main() {
    cin >> N;
    nums = (int *)malloc(sizeof(int) * N);
    int n = sqrt(N);
    for (int i = n; i >= 1; i--) {
        if (N % i == 0) {
            n = i;
            break;
        }
    }
    int m = N / n;
    for (int i = 0; i < N; i++) {
        scanf("%d", nums + i);
    }
    sort(nums, nums + N, [](int a, int b) -> bool { return a > b; });
    result = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        result[i] = (int *)malloc(sizeof(int) * n);
    }
    fiil_nums(0, 0, m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", result[i][j]);
            printf(j == n - 1 ? "\n" : " ");
        }
    }
    return 0;
}