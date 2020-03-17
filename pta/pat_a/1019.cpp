#include <iostream>
#include <vector>
using namespace std;

bool isPalindromic(vector<int> num) {
    for (int i = 0; i < num.size() / 2; i++) {
        if (num[i] != num[num.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<int> toBase(int num, int base) {
    if (num == 0) {
        return vector<int>{0};
    }
    vector<int> result;
    while (num) {
        // result.push_back(num % base);
        result.insert(result.begin(), num % base);
        num = num / base;
    }
    return result;
}

int main() {
    int n, b;
    cin >> n >> b;
    vector<int> num = toBase(n, b);
    printf(isPalindromic(num) ? "Yes\n" : "No\n");
    for (int i = 0; i < num.size(); i++) {
        printf("%d", num[i]);
        printf(i == num.size() - 1 ? "\n" : " ");
    }
    return 0;
}