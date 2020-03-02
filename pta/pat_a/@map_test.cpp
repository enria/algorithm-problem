#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> m;
    m[3] = 123;
    m[1] = 456;
    m[2] = 789;
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->first<<endl;
    }

    return 0;
}