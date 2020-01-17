/*
使用管道进行进程通信
*/
#include <iostream>
#include <unistd.h>
using namespace std;

void anypipe();
int main(int argc, char const *argv[]) {
    anypipe();
    return 0;
}

void anypipe() {
    int pipefd[2];
    if (pipe(pipefd) < 0) {
        exit(1);
    }
    printf("PIPE: Read end = fd %d, write end = fd %d\n", pipefd[0], pipefd[1]);
    string mesg = "hello everyone";
    int wcount, rcount, len = mesg.length();
    if ((wcount = write(pipefd[1], mesg.c_str(), mesg.length())) != len) {
        exit(1);
    }
    char buf[BUFSIZ];
    if ((rcount = read(pipefd[0], buf, BUFSIZ)) != wcount) {
        exit(1);
    }
    cout << buf<<endl;
}
//使用shell `|` 的方式定向输入
int shell() {
    string s;
    freopen("data.out", "w", stdout);
    while (cin >> s) {
        cout << s << endl;
    }

    return 0;
}