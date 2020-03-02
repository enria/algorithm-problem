#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int main() {
    string text = "Quick brown fox.";
    regex ws_re("\\s+");  // whitespace
    vector<string> v(sregex_token_iterator(text.begin(), text.end(), ws_re, -1),
                     sregex_token_iterator());
    for (auto s : v) cout << s << endl;
    return 0;
}