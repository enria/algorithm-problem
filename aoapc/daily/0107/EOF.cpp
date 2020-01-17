/*
1. 如何使用EOF？
    1.1 使用键盘输入时
        1.1.1 windows
            首先在最后一行结束后（此时未换行）输入ENTER键，新起一行，再输入ctrl+z，再输入时ENTER键即可。
        1.1.2 Linux:
            直接按CTRL+D快捷键
    1.2 使用文件时
        文件读完时就会碰到EOF

2. while (cin >> s)为什么会终止？
    cin是C++的标准输入流，其本身是一个对象，并不存在返回值的概念。
    不过经常会有类似于while(cin>>a)的调用，这里并不是cin的返回值，而是>>操作重载函数
    istream&
operator>>(istream&,T&);的返回值，其中第二个参数由cin>>后续参数类型决定。
    其返回值类型为istream&类型，大多数情况下其返回值为cin本身（非0值），只有当遇到EOF输入时，返回值为0。
    输入EOF的方法，windows下输入ctrl+z, Linux下输入ctrl+d。
    于是，当输入所有数据后，通过输入EOF的方法，可以退出while(cin>>a)这样的循环。
*/
#include <iostream>

using namespace std;

int main() {
    string s;
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    while (cin >> s) {
        cout << s << endl;
    }

    return 0;
}