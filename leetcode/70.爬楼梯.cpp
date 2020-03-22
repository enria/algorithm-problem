#include <iostream>

using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        int opts[n + 1];
        opts[0] = 1;
        opts[1] = 1;
        for (int i = 2; i <= n; i++) {
            opts[i] = opts[i - 2] + opts[i - 1];
        }
        return opts[n];
    }
};

int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.climbStairs(n) << endl;
    return 0;
}