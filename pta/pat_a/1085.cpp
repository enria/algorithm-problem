#include <algorithm>
#include <iostream>
using namespace std;
long nums[100010];

int noGrater(int start, int end, long target) {  //两端都是能取到的
    if (nums[start] > target) {
        return -1;
    }
    
    if (end - start <= 1) {
        return nums[end] <= target ? end : start;
    }

    if (nums[(start + end) / 2] > target) {
        return noGrater(start, (start + end) / 2 - 1, target);
    } else {
        return noGrater((start + end) / 2, end, target);
    }
}

int main() {
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        scanf("%ld", nums + i);
    }
    sort(nums, nums + n);
    int len = 1;
    for (int i = 0, index; i < n - 1; i++) {
        index = noGrater(i + 1, n - 1, nums[i] * p);
        if (index > -1 && index - i + 1 > len) {
            len = index - i + 1;
        }
    }
    printf("%d\n", len);
    return 0;
}