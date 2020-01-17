#include <iostream>

using namespace std;

void move(int n, string a, string b, string c) {
    if (n > 1) {
        move(n - 1, a, c, b);
        cout << "将" << n << "移动到" << c << endl;
        move(n - 1, b, a, c);
    } else {
        cout << "将" << n << "移动到" << c << endl;
    }
}

int main() {
    move(20, "第一个柱子", "第二个柱子", "第三个柱子");
    return 0;
}