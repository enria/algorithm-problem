#include <iostream>
#include <set>

using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    set<char> cs;
    for (int i = 0; i < b.length(); i++) {
        cs.insert(b.at(i));
    }

    for (int i = 0; i < a.length(); i++) {
        if (!cs.count(a.at(i))) {
            printf("%c", a.at(i));
        }
    }
    printf("\n");

    return 0;
}