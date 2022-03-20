// C++的 bitset 在 bitset 头文件中，它是一种类似数组的结构，它的每一个元素只能是０或１，每个元素仅用１bit空间。

#include <iostream>
#include <bitset>

using namespace std;

int gcd(int a,int b){return !b?a:gcd(b,a%b);}


int count_ones(char _num) {
    bitset<8> a(_num);
    return a.count();
}

int main(){
    int n;
    scanf("%d",&n);getchar();
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        pair<int,int> sret={0,0};
        for(auto c:s){
            int ret=count_ones(c);
            sret.first+=ret;
            sret.second+=8;
        }
        int g=gcd(sret.first,sret.second);
        printf("%d/%d\n",sret.first/g,sret.second/g);
    }
}