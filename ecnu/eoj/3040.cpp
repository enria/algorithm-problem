#include <bitset>
#include <iostream>

// #define ll long long
using namespace std;

int ml(bitset<32> bi){
    int m=1,start=0;
    for(int i=bi.size()-1;i>=0&&bi[i]==0;i--){
        start=i-1;
    }
    for(int i=start-1;i>=0;i--){
        if(bi[i]==bi[i+1]){
            int l=start-(i+1)+1;
            if(l>m) m=l;
            start=i;
        }else{
            if(i==0){
                int l=start-(i)+1;
                if(l>m) m=l;
            } 
        }
    }
    return m;
}

int main(){
    int n;
    cin >> n;
    for(int j=0;j<n;j++){
        int i;
        cin>>i;
        bitset<32> bi(i);
        int m=ml(bi);
        printf("case #%d:\n%d\n",j,m);
    }
}