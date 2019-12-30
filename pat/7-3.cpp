#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string n;
    cin >> n;
    reverse(n.begin(), n.end());
    cout << stoi(n);
    return 0;
}