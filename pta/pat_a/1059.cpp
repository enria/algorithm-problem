#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int num) {
    if (num == 1) return 0;
    if (num == 2 || num == 3) return 1;
    if (num % 6 != 1 && num % 6 != 5) return 0;
    for (int i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    return 1;
}
struct Factor {
    int prime, exp;
};
int main() {
    long num, origin;
    cin >> num;
    if (num == 1) {
        printf("%ld=%ld\n", num, num);
        return 0;
    }
    origin = num;
    vector<Factor> result;
    // 17=17^1，不要把的算素数的那个方法套到这里来了
    for (int i = 2; i <= origin && num > 1; i++) {
        if (is_prime(i) && num % i == 0) {
            int exp = 0;
            while (num > 1 && num % i == 0) {
                num = num / i;
                exp++;
            }
            result.push_back(Factor{i, exp});
        }
    }
    printf("%ld=", origin);
    for (int i = 0; i < result.size(); i++) {
        if (i != 0) printf("*");
        if (result[i].exp == 1) {
            printf("%d", result[i].prime);
        } else {
            printf("%d^%d", result[i].prime, result[i].exp);
        }
    }
    printf("\n");
    return 0;
}