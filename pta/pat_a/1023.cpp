#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

pair<bool, string> is_permutation(string num) {
    int n = num.length();
    char dc[num.length() + 1];
    dc[num.length()]=0;//TODO last=0
    int jw = 0;
    while (n--) {//TODO n--
        int bi = (num.at(n) - '0') * 2 + jw;
        jw = bi / 10;
        dc[n] = (bi % 10) + '0';
    }
    string s2 = dc;
    if (jw) {
        char c = '0' + jw;
        string pre = {c,'\0'};
        return pair<bool, string>(false, pre + s2);
    }
    char c1[num.length() + 1], c2[num.length() + 1];
    c1[num.length()]=0,c2[num.length()]=0;
    strcpy(c1, num.data()), strcpy(c2, s2.data());//TODO strcpy
    sort(c1, c1 + num.length()), sort(c2, c2 + num.length());
    string s1 = c1;
    string s3 = c2;
    return pair<bool, string>(s1.compare(s3) == 0, s2);
}

int main() {
    string num;
    cin >> num;
    pair<bool, string> result = is_permutation(num);
    cout << (result.first ? "Yes" : "No") << endl;
    cout << result.second << endl;
    return 0;
}