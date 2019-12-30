#include <iostream>

using namespace std;


int main() {
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    n=n%s.length();
    char s2[s.length()+1];
    for (int i = 0; i < n; i++) {
        s2[i + (s.length() - n)] = s[i];
    }
    for (int i = n; i < s.length(); i++) {
        s2[i - n] = s[i];
    }
    s2[s.length()]=0;
    cout << s2;
    return 0;
}