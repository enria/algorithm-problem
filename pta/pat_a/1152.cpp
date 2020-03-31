#include <iostream>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return false;
    return true;
}

int main() {
    int l, k;
    string num;
    cin >> l >> k >> num;
    string sol = "404";
    for (int i = 0; i + k <= l; i++) {
        string seg = num.substr(i, k);
        if (isPrime(stoi(seg))) {
            sol = seg;
            break;
        }
    }
    cout << sol << endl;
    return 0;
}