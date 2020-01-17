#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int decimal;
    stringstream ss;
    cin >> decimal;
    ss << hex << decimal; // TODO 输出16进制数
    cout << ss.str() << endl;
    return 0;
}