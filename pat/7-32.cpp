#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str;
    getline(cin,str);
    str += " ";
    string temp = "";
    vector<string> ts(0);
    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) != ' ') {
            temp += str.at(i);
        } else {
            if (temp != "") {
                ts.push_back(temp);
                temp = "";
            }
        }
    }
    reverse(ts.begin(), ts.end());
    for (int i = 0; i < ts.size(); i++) {
        cout << ts[i];
        if(i!=ts.size()-1){
            cout << ' ';
        }
    }
    return 0;
}