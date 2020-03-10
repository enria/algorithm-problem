#include <iostream>
#include <vector>

using namespace std;
string digit[] = {"ling", "yi", "er", "san", "si", "wu",
                  "liu",  "qi", "ba", "jiu", "10"};
string weight[] = {"", " Wan", " Yi"};

string ww[] = {"", " Shi", " Bai", " Qian"};

string qw(int num) {
    if (num == 0) {
        return "ling";
    }
    string result = "";
    int ws[4];

    for (int i = 0, zhi; i < 4; i++) {
        ws[i] = num % 10;
        num = num / 10;
    }
    bool zp = false, start = false;  //需不需要前面加0
    for (int i = 3; i >= 0; i--) {
        if (ws[i] == 0) {
            if (start) zp = true;
        } else {
            if (start) {
                result += " ";
            }
            if (zp) {
                result += digit[0] + " ";
                zp = false;
            }
            result += digit[ws[i]] + ww[i];
            start = true;
        }
    }
    return result;
}

string toChinese(int num) {
    if (num == 0) {
        return "ling";
    }
    string result = "";
    if (num < 0) {
        result = "Fu ";
        num = -num;
    }
    vector<int> qws;
    while (num) {
        qws.push_back(num % 10000);
        num = num / 10000;
    }
    bool zp = false;
    for (int i = qws.size() - 1; i >= 0; i--) {
        if (qws[i] == 0) {
            zp = true;
        } else {
            if (i != qws.size() - 1) result += " ";
            if (zp) {
                result += digit[0] + " ";
                zp = false;
            } else {
                if (qws[i] < 1000 && i != qws.size() - 1) {
                    result += digit[0] + " ";
                }
            }
            result += qw(qws[i]) + weight[i];
        }
    }
    return result;
}

int main() {
    int num;
    cin >> num;
    printf("%s\n", toChinese(num).c_str());
    return 0;
}