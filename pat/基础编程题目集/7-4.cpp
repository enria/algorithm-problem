#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int decimal;
    stringstream ss, sss;
    cin >> decimal;
    ss << hex << decimal;
    cout << ss.str() << endl;
    return 0;
}