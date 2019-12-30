#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b) {
        cout << "C";
    } else {
        if (a == c) {
            cout << "B";
        } else {
            cout << "A";
        }
    }
    return 0;
}