#include <iostream>

using namespace std;

string desc(string num) {
    int cnt = 1;
    char last = num.at(0);
    string result = "";
    for (int i = 1; i < num.size(); i++) {
        if (num[i] == last) {
            cnt++;
        } else {
            result += last + to_string(cnt);
            last = num[i], cnt = 1;
        }
    }
    result += last + to_string(cnt);
    return result;
}
int main() {
    int d, n;
    cin >> d >> n;
    string num = to_string(d);
    for (int i = 2; i <= n; i++) {
        num = desc(num);
    }
    cout << num << endl;
    return 0;
}