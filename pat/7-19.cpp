#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int y = 0; y < 50; y++) {
        for (int f=0; f < 100; f++) {
            if(100*f+y-n==200*y+2*f){
                cout<<y<<"."<<f;
                return 0;
            }
        }
    }
    cout<<"No Solution";
    return 0;
}