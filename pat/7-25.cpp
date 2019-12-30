#include <iostream>
#include <map>

using namespace std;

map<char, string> dict = {{'-', "fu"}, {'0', "ling"}, {'1', "yi"},
                          {'2', "er"}, {'3', "san"},  {'4', "si"},
                          {'5', "wu"}, {'6', "liu"},  {'7', "qi"},
                          {'8', "ba"}, {'9', "jiu"}};

int main() {
    string num;
    cin >> num;
    for (int i = 0; i < num.length(); i++) {
        cout << dict[num.c_str()[i]];
        if (i != num.length() - 1)
            cout << " ";
    }
    return 0;
}