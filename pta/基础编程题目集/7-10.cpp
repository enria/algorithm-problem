#include <iostream>

using namespace std;

#define X 30
#define L 50

int main() {
    int y, h;
    scanf("%d %d", &y, &h);
    int sh = y < 5 ? X : L;
    double sz = h > 40 ? (h - 40) * sh * 1.5 + 40 * sh : h * sh;
    printf("%.2f", sz);
    return 0;
}