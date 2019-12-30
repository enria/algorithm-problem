#include <math.h>
#include <iostream>

using namespace std;

#define precision 0.01

float expValue(float x, float a1, float a2, float a3, float a4) {
    return a1 * pow(x, 3) + a2 * pow(x, 2) + a3 * pow(x, 1) + a4;
}

int main() {
    float a1, a2, a3, a4;
    float a, b;
    scanf("%f %f %f %f", &a1, &a2, &a3, &a4);
    scanf("%f %f", &a, &b);
    if (expValue(a, a1, a2, a3, a4)==0) {
        printf("%.2f", a);
        return 0;
    }
    if (expValue(b, a1, a2, a3, a4)==0) {
        printf("%.2f", b);
        return 0;
    }
    while (b - a > precision) {
        float c = (b + a) / 2;
        float value = expValue(c, a1, a2, a3, a4);
        if (value == 0) {
            break;
        } else if (expValue(a, a1, a2, a3, a4) * expValue(c, a1, a2, a3, a4) <
                   0) {
            b = c;
        } else {
            a = c;
        }
    }
    printf("%.2f", (a + b) / 2);
    return 0;
}