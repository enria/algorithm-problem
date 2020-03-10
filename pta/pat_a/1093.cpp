#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
#define MAX 100010
#define MOD 1000000007
int tc[MAX], atc[MAX];  //存放i处及之后有多少个t

int main() {
    char str[MAX];
    cin >> str;  // TODO char[]的长度 GET
    int ti = 0, len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == 'T') ti++;
        tc[i] = ti;
    }
    int ati = 0;
    for (int i = len - 2; i >= 1; i--) {
        if (str[i] == 'A') {
            ati = (ati + tc[i + 1]) % MOD;
        }
        atc[i] = ati;
    }
    int total = 0;
    for (int i = 0; i < len - 2; i++) {
        if (str[i] == 'P') {
            total = (total + atc[i + 1]) % MOD;
        }
    }
    printf("%d\n", total);
    return 0;
}