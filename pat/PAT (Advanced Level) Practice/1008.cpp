#include <iostream>

using namespace std;



int main() {
    int n;
    cin >> n;
    int cur_f = 0;
    long time = 0;
    for (int i = 0; i < n; i++) {
        int req;
        cin >> req;
        if (req > cur_f) {
            time += (req - cur_f) * 6 + 5;
        } else {
            time += (cur_f - req) * 4 + 5;
        }
        cur_f=req;
    }
    cout << time<<endl;
    return 0;
}