#include <iostream>

using namespace std;
long long factorial(int n) {
    long long m = 1;
    for (int i = 1; i <= n; i++) {
        m *= i;
    }
    return m;
}
int main() {
    cout << factorial(20) << endl;
    return 0;
}