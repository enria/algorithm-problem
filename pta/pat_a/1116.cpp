#include <iostream>
#include <map>

bool isPrime(int num) {
    if (num == 1) return 0;
    if (num == 2 || num == 3) return 1;
    if (num % 6 != 1 && num % 6 != 5) return 0;
    for (int i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    return 1;
}

using namespace std;

int main() {
    map<int, int> cache;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int id;
        scanf("%d", &id);
        cache[id] = i;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int id;
        scanf("%d", &id);
        printf("%04d: ", id);
        if (cache[id]) {
            if (cache[id] == 1) {
                printf("Mystery Award\n");
            } else if (cache[id] == -1) {
                printf("Checked\n");
            } else if (isPrime(cache[id])) {
                printf("Minion\n");
            } else {
                printf("Chocolate\n");
            }
            cache[id] = -1;
        } else {
            printf("Are you kidding?\n");
        }
    }
    return 0;
}