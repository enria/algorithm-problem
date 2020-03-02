#include <iostream>

using namespace std;

#define SPEED "Speeding"
#define OK "OK"

int main() {
    int n;
    cin >> n;
    cout << "Speed: " << n << " - " << (n > 60 ? SPEED : OK);
    return 0;
}