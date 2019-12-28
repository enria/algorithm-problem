#include <iostream>

using namespace std;

int main() {
    int cur, m;
    cin >> cur;
    cin >> m;
    int curh = cur / 100;
    int curm = cur - curh * 100;
    curm += m;
    curh += curm / 60;
    curm = curm % 60;
    if(curm<0){
        curh--;
        curm+=60;
    }
    cout << curh;
    printf("%02d", curm);
    return 0;
}