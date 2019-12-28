#include <iostream>

using namespace std;
int* digit(int nums[][2],int n);
int main(void) {
    int n;
    cin >> n;
    int oprands[n][2];
    for (int i = 0; i < n; i++) {
        cin >> oprands[i][0];
        cin >> oprands[i][1];
    }
    int* digits = digit(oprands,n);
    for (int i = 0; i < n; i++) {
        cout << digits[i] << endl;
    }
    return 0;
}

int digit(int n) {
    return to_string(n).length();
}

int* digit(int nums[][2], int n) {
    int* digits = new int[n];
    for (int i = 0; i < n; i++) {
        digits[i]=digit(nums[i][0] + nums[i][1]);
    }
    return digits;
}