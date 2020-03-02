#include <iostream>

using namespace std;
int main() {
    int c1, c2;
    cin >> c1;
    long n1[c1];
    for (int i = 0; i < c1; i++) {
        cin >> n1[i];
    }
    cin >> c2;
    long n2[c2];
    for (int i = 0; i < c2; i++) {
        scanf("%ld", &n2[i]);
    }

    int cnt = 0;                 //已经取到的数
    int md = (c1 + c2 + 1) / 2;  //需要取多少个数
    int num;
    int i1 = 0, i2 = 0;  //当前的指向（未取到）

    while (cnt < md) {
        if (i1 == c1) {//n1已经取完，将n2取到中位数即可
            num = n2[md - c1 - 1];
            break;
        }
        if (i2 == c2) {//同理
            num = n1[md - c2 - 1];
            break;
        }
        if (n1[i1] < n2[i2]) {
            num = n1[i1];
            i1++;
            cnt++;
        } else {
            num = n2[i2];
            i2++;
            cnt++;
        }
    }
    cout << num << endl;
    return 0;
}