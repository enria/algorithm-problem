#include <iostream>
using namespace std;

#define AM "AM"
#define PM "PM"

int main() {
    int h, m;
    string ma = AM;
    scanf("%d:%d", &h, &m);
    if (h > 12) {
        h -= 12;
        ma = PM;
    }
    if (h == 12) {
        ma = PM;
    }
    cout << h << ":" << m << " " << ma;
    return 0;
}