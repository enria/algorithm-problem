#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str = "";
    char i;
    while ((i = getchar()) != '.') {
        str += i;
    }
    str+=" ";
    string temp;
    vector<int> ts(0);
    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) != ' ') {
            temp += str.at(i);
        } else {
            if (temp != "") {
                ts.push_back(temp.length());
                temp = "";
            }
        }
    }
    for (int i = 0; i < ts.size(); i++) {
        cout << ts[i];
        if (i != ts.size() - 1)
            cout << " ";
    }
    return 0;
}