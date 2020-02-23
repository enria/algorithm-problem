#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;
char FLAGS[] = {'W', 'T', 'L'};

int main() {
    float odds[3][3];
    int choose[3];
    memset(choose, 0, sizeof(int) * 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> odds[i][j];
            if (odds[i][j] > odds[i][choose[i]]) {
                choose[i] = j;
            }
        }
    }
    float profit = 1;
    for (int i = 0; i < 3; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << FLAGS[choose[i]];
        profit *= odds[i][choose[i]];
    }
    profit = profit * 0.65 * 2 - 2;
    printf(" %.2f\n",profit);
    return 0;
}