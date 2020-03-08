#include <iostream>
#include <map>

using namespace std;
char chars[1048580];
int main() {
    map<string, int> dict;
    cin.getline(chars, 1048580);
    int cur = 0;
    string temp;
    while (chars[cur]) {
        if (chars[cur] <= '9' && chars[cur] >= '0') {
            temp += chars[cur];
        } else if (chars[cur] <= 'z' && chars[cur] >= 'a') {
            temp += chars[cur];
        } else if (chars[cur] <= 'Z' && chars[cur] >= 'A') {
            temp += chars[cur] + ('a' - 'A');
        } else {
            if (temp.length() > 0) {
                dict[temp]++;
                temp = "";
            }
        }
        cur++;
    }
    if (temp.length() > 0) {
        dict[temp]++;
    }
    int max_cnt = 0;
    string max_token;
    for (auto it = dict.begin(); it != dict.end(); it++) {
        if (it->second > max_cnt) {
            max_cnt = it->second;
            max_token = it->first;
        }
    }
    printf("%s %d\n", max_token.c_str(), max_cnt);
    return 0;
}