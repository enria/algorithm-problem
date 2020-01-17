#include <iostream>

using namespace std;

typedef struct {
    int d = 0;
    void operator+=(int b) { d = d + 2; }
} a;

int main() {
    a b;
    b += 100;
    cout << b.d << endl;
    return 0;
}