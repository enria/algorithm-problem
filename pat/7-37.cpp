#include <math.h>
#include <iostream>

using namespace std;

bool isZ(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    /*body*/
    return 0;
}