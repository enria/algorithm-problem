#include <iostream>

using namespace std;

int main() {
    int from, end;
    scanf("%d %d", &from, &end);
    int t = 1;
    for (int i = from; i <= end; i++,t++) {
        printf("%5d", i);
        if (t % 5 == 0) {
            cout << endl;
        }
    }
    if (t % 5 != 1)
        cout << endl;
    cout << "Sum = " << (from + end) * (end - from + 1) / 2;
    return 0;
}