#include <iostream>
#include <vector>

using namespace std;

struct fraction {
    long long numerator;
    long long denominator;
};

long long exgcd(long long a, long long b) {
    if (b == 0)
        return a;
    exgcd(b, a % b);
}
long long multiple(vector<fraction> fracs) {
    long long ans = fracs[0].denominator;
    for (int i = 1; i < fracs.size(); i++) {
        long long r = exgcd(ans, fracs[i].denominator);
        ans = ans / r * fracs[i].denominator;  ///先除后乘，防止溢出
    }
    return ans;
}

fraction toFractoin(string str) {
    fraction f;
    string temp = "";
    for (int i = 0; i < str.length(); i++) {
        temp += str.at(i);
        if (str.at(i) == '/') {
            f.numerator = stoi(temp);
            temp = "";
        }
        if (i == str.length() - 1) {
            f.denominator = stoi(temp);
        }
    }
    return f;
}

fraction sum(vector<fraction> fracs) {
    long long multi = multiple(fracs);
    long long numSum = 0;
    for (int i = 0; i < fracs.size(); i++) {
        int m = multi / fracs[i].denominator;
        numSum += fracs[i].numerator * m;
    }
    long long div = exgcd(numSum, multi);
    fraction ans;
    ans.numerator = numSum / div;
    ans.denominator = multi / div;
    return ans;
}

int main() {
    vector<fraction> fractions(0);
    for (int i = 0; i < 2; i++) {
        string exp;
        cin >> exp;
        fraction f = toFractoin(exp);
        fractions.push_back(f);
    }
    fraction ans = sum(fractions);
    cout << ans.numerator;
    if (ans.denominator != 1) {
        cout << "/" << ans.denominator;
    }
    return 0;
}