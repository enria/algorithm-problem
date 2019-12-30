#include <iostream>

using namespace std;

int main() {
    string s, a;
    getline(cin, s);
    getline(cin, a);
    int pos = s.find(a);
    while (pos >= 0) {
        s.replace(pos, a.length(), "");
        pos= s.find(a);
    }
    cout << s;
    return 0;
}