#include <iostream>

using namespace std;

int main() {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        string nums = to_string(num);
        int n1 = stoi(nums.substr(0, nums.size() / 2)),
            n2 = stoi(nums.substr(nums.size() / 2));
        if (n1 * n2 == 0 || num % (n1 * n2)) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}