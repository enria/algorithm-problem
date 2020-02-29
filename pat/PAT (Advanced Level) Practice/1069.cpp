#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
int main() {
    string ns;
    cin >> ns;
    while (true) {
        char nsc[5], rnsc[5];
        snprintf(nsc, sizeof(nsc), "%04d", stoi(ns));//格式化输出到字符串
        sort(nsc, nsc + 4, [](char a, char b) -> bool { return b < a; });
        snprintf(rnsc, sizeof(rnsc), "%04d", stoi(ns));
        sort(rnsc, rnsc + 4);
        string nss = nsc, rnss = rnsc;
        int result = stoi(nss) - stoi(rnss);
        printf("%04d - %04d = %04d\n", stoi(nss), stoi(rnss), result);
        if (result == 6174 || result == 0) break;
        ns = to_string(result);
    }
    return 0;
}