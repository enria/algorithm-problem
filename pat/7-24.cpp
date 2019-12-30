#include <iostream>

using namespace std;
int exgcd(int a, int b) {
    if (b == 0)
        return a;
    exgcd(b, a % b);
}
int main() {
    int a, b;
    scanf("%d/%d", &a, &b);
    int gcd = exgcd(a, b);
    printf("%d/%d", a / gcd, b / gcd);
    return 0;
}