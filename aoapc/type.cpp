#include <iostream>

using namespace std;

int main() {
    double a = 1.11111111111111111111111111;
    double *c = &a;
    int *d = (int *)c;
    cout << *d << endl;
    return 0;
}