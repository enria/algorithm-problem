/*移位操作*/
#include <iostream>

using namespace std;

int main() {
    for (int a = 0; a < 65536; a++) {
        for (int i = 0; i < 16; i++) {
            if (a & (1 << i))
                printf("%d ", i+1);
        }
        cout << endl;
    }
    return 0;
}