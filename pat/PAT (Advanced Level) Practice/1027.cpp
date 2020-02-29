#include <iostream>

using namespace std;

string dict[]={"0","1","2","3","4","5","6","7","8","9","A","B","C"};

string to13(int n){
    int gw=n%13;
    int sw=n/13;
    return dict[sw]+dict[gw];
}

int main()
{
    string a="123""456";
    cout<<a<<endl;
    return 0;
    int r,g,b;
    cin>>r>>g>>b;
    cout<<"#"<<to13(r)<<to13(g)<<to13(b)<<endl;
    return 0;
}