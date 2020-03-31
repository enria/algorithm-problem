#include <iostream>

#define MAX 100010
using namespace std;
int nums[MAX];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (num > 0 && num < MAX) {
            nums[num]++;
        }
    }
    for (int i = 1; i < MAX; i++) {
        if (nums[i] == 0) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}