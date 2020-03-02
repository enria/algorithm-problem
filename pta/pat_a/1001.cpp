#include <iostream>
#include <vector>

using namespace std;

// A+B Format
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int c = a + b;
    int s = c < 0 ? 1 : 0;
    string cs = to_string(c);
    int ss = (cs.length() - s) % 3;
    if (ss == 0)
        ss = 3;
    ss += s;
    for (int i = 0; i < cs.length(); i++) {
        cout << cs.at(i);
        if (i + 1 == ss&&i!=cs.length()-1) {
            cout << ",";
            ss += 3;
        }
    }
    cout << endl;
    return 0;
}