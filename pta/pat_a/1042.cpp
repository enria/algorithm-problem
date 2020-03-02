#include <iostream>

using namespace std;

int main() {
    int *source, *dest;
    source = (int *)malloc(sizeof(int) * 55);
    dest = (int *)malloc(sizeof(int) * 55);
    int ord[55];
    for (int i = 1; i < 55; i++) {
        source[i] = i;
    }
    int n;
    cin >> n;
    for (int i = 1; i < 55; i++) {
        cin >> ord[i];
    }

    while (n--) {
        for (int i = 1; i < 55; i++) {
            dest[ord[i]] = source[i];
        }
        int *temp;
        temp = source;
        source = dest;
        dest = temp;
    }
    char hs[] = {'S', 'H', 'C', 'D', 'J'};
    for (int i = 1; i < 55; i++) {
        int od = source[i] - 1;
        cout << (i == 1 ? "" : " ") << hs[od / 13] << od % 13 + 1;
    }
    cout << endl;

    return 0;
}