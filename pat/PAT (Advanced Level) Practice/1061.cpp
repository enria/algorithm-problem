#include <iostream>

using namespace std;

string xq[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    string l1, l2, l3, l4;
    cin >> l1 >> l2 >> l3 >> l4;
    int d = -1, h, m;
    for (int i = 0; i < l1.length(); i++) {
        if (l1.at(i) == l2.at(i)) {
            char c = l1.at(i);
            if (d == -1) {
                if (c <= 'Z' && c >= 'A') {
                    d = c - 'A';
                }
            } else {
                if (c >= '0' && c <= '9') {
                    h = c - '0';
                    break;
                }
                
                if (c >= 'A' && c <= 'Z') {
                    h = (c - 'A') + 10;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < l3.length(); i++) {
        if (l3.at(i) == l4.at(i)) {
            int c = l3.at(i);
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                m = i;
                break;
            }
        }
    }
    printf("%s %02d:%02d\n",xq[d].c_str(),h,m);
    return 0;
}