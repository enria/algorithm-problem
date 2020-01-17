/*
struct {} m[26]是什么意思？
答案是申明一个全局变量。
 */
#include <iostream>

using namespace std;

void test();

struct point {
    int a;
} m[26];

int main() {
    m[0].a = 1234;
    point a;
    a.a = 4;
    cout << a.a;
    return 0;
}

void test() { cout << m[0].a << endl; }