#include <iostream>

using namespace std;
void swap(int a,int b){
    int t=a;
    a=b;
    b=t;
}
int main() {
    int a=3,b=4;
    swap(a,b);
    printf("%d %d\n",a,b);//TODO 1:gdb命令;2:gdb使用方法
    return 0;
}