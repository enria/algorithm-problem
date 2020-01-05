#include <iostream>

using namespace std;

int main() {
    int a, b;
    char op;
    cin >> a, cin >> op, cin >> b;
    switch (op) {
        case '+':
            cout << a + b;
            break;
        case '-':
            cout << a - b;
            break;
        case '*':
            cout << a * b;
            break;
        case '/':
            cout << a / b;
            break;
        case '%':
            cout << a % b;
            break;
        default:
            cout << "ERROR";
    }
    return 0;
}