#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(int num) {
    if (num == 1) return 0;
    if (num == 2 || num == 3) return 1;
    if (num % 6 != 1 && num % 6 != 5) return 0;
    int tmp = sqrt(num);
    for (int i = 5; i <= tmp; i += 6)
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    return 1;
}

// TODO int 不返回的默认值？
string to_redix_reverse(int n, int d) {
    string result = "";  // TODO string默认值
    int k;
    while (n > 0) {
        k = n % d;
        n = n / d;
        result += to_string(k);
    }
    return result;
}

int to_decimal(string n, int d) {
    int result = 0;
    int w = 1;
    for (int i = n.size() - 1; i >= 0; i--, w = w * d) {
        result += w * (n.at(i) - '0');
    }
    return result;
}


int main() {
    while (1) {
        int n, d;
        cin >> n;
        if (n < 0) {
            break;
        }
        cin >> d;
        int reverse=to_decimal(to_redix_reverse(n,d),d);
        if(is_prime(n)&&is_prime(reverse)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}