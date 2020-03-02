#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ds[n + 1];//下标从1开始使用
    for (int i = 1; i < n + 1; i++) {
        cin >> ds[i];
    }
    int fto1[n + 1], fto2[n + 1];//代表从1到i的距离，前一个是正着，后一个是反着
    fto1[1]=0,fto2[1]=0;
    fto1[2] = ds[1], fto2[n] = ds[n];
    for (int i = 3; i <= n; i++) {
        fto1[i] = fto1[i - 1] + ds[i - 1];
    }
    for (int i = n - 1; i >= 2; i--) {
        fto2[i] = fto2[i + 1] + ds[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int d1 = abs(fto1[a] - fto1[b]);
        int d2 = b>a?fto2[b]+fto1[a]:fto2[a]+fto1[b];
        cout << min(d1, d2) << endl;//正反两个方向中的最小距离
    }
    return 0;
}