#include <algorithm>
#include <iostream>
using namespace std;

struct Mooncake {
    float inventory;
    float price, price_per;
    bool operator<(Mooncake cake) { return price_per > cake.price_per; }
};

int main() {
    int n;
    float demand;  //坑，没说可能是浮点数
    cin >> n >> demand;
    Mooncake cakes[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &cakes[i].inventory);
    }
    for (int i = 0; i < n; i++) {
        scanf("%f", &cakes[i].price);
        cakes[i].price_per = cakes[i].price / cakes[i].inventory;
    }
    sort(cakes, cakes + n);
    float profit = 0, sell = 0;
    for (int i = 0; i < n; i++) {
        //不要考虑相等的情况，事实上因为浮点数的相加基本上不可能出现相等的可能
        if (cakes[i].inventory + sell > demand) {
            profit += (demand - sell) * cakes[i].price_per;
            break;
        } else {
            profit += cakes[i].price;
            sell += cakes[i].inventory;
        }
    }
    printf("%.2f\n", profit);
    return 0;
}