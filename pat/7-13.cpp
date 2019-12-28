#include <iostream>

using namespace std;

int main() {
    float open, high, low, close;
    scanf("%f %f %f %f", &open, &high, &low, &close);
    if (open == close) {
        cout << "R-Cross";
    } else if (open > close) {
        cout << "BW-Solid";
    } else {
        cout << "R-Hollow";
    }
    bool lb = low < open && low<close, hb = high> open && high > close;
    if (lb && hb) {
        cout << " with Lower Shadow and Upper Shadow";
    } else if (lb) {
        cout << " with Lower Shadow";
    } else if (hb) {
        cout << " with Upper Shadow";
    }
    return 0;
}