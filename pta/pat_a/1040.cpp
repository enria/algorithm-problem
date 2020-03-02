#include <iostream>

using namespace std;
string str;
bool symmetric(int start, int end) {
    while (start <= end) {
        if (str.at(start) != str.at(end)) {
            return false;
        }
        start++,end--;
    }
    return true;
}

int main() {
    getline(cin, str);
    for (int len = str.length(); len >= 1; len--) {
        for (int i = 0; i + len <= str.length(); i++) {
            if (symmetric(i, i + len - 1)) {
                printf("%d\n", len);
                return 0;
            }
        }
    }
    return 0;
}