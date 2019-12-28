#include <math.h>
#include <iostream>

using namespace std;

int main() {
    int cm;
    cin >> cm;
    float m = cm / 0.3048 / 100;
    int foot = floor(m);
    int inch = floor((m - foot) * 12);
    cout << foot << " " << inch;
    return 0;
}