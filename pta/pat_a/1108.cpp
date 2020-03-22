#include <cstring>
#include <iostream>

using namespace std;

bool valid(const char* num) {
    int len = strlen(num);
    int point = 0;
    for (int i = 0; i < len; i++) {
        char cur = num[i];
        if (cur <= '9' && cur >= '0') {
            if (point && i - point > 2) {
                return false;
            }
        } else if (cur == '-') {
            if (i != 0) return false;
        } else if (cur == '.') {
            if (i == 0 || point) return false;
            point = i;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool v = false;
        string num;
        cin >> num;
        if (num.size() <= 10 && valid(num.c_str())) {
            try {
                double _num = stod(num);
                if (_num <= 1000.00 && _num >= -1000.00) {
                    sum += _num;
                    cnt++;
                    v = true;
                }
            } catch (const std::exception& e) {
                // printf("%s\n", e.what);
            }
        }
        if (!v) {
            printf("ERROR: %s is not a legal number\n", num.c_str());
        }
    }
    switch (cnt) {
        case 0:
            printf("The average of 0 numbers is Undefined\n");
            break;
        case 1:
            printf("The average of 1 number is %.2f\n", sum);
            break;
        default:
            printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
            break;
    }
    return 0;
}