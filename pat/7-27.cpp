#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
        if (i + 1 == k) {
            for (int k = 0; k < n; k++) {
                cout << nums[k];
                if (k != n - 1)
                    cout << " ";
            }
            return 0;
        }
    }
}