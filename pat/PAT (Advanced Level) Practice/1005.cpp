#include <string.h>
#include <iostream>
using namespace std;

char s[101];
string DICT[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main() {
    memset(s, 0, sizeof(char) * 101);
    cin >> s;
    int sum = 0;
    char c;
    for (int i = 0; s[i]; i++) {
        sum += (s[i] - 48);
    }
    string ss = to_string(sum);
    for (int i = 0; i < ss.length(); i++) {
        int num = ss.at(i) - 48;
        cout << (i == 0 ? DICT[num] : " " + DICT[num]);
    }
    cout << endl;
    return 0;
}