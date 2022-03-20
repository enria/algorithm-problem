#include <iostream>
using namespace std;

#define MAX 5*1000000

int nums[MAX];
int dp[MAX][MAX];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&(nums[i]));
    }
    int cur=0;
    for(int i=0;i<n;i++){
        if(nums[i]==i+1){
            cur+=1;
        }
    }
    int max_inc=0;
    if(cur!=n){
        for(int i=1;i<n;i++){
            for(int j=0;j<n-i;j++){
                int org=0,inc=0;
                if(j+i+1==nums[j+i])org+=1;
                if(j+1==nums[j])org+=1;
                if(j+i+1==nums[j]) inc+=1;
                if(j+1==nums[j+i]) inc+=1;
                dp[j][j+i]=(inc-org)+dp[j+1][j+i-1];
                if(max_inc<dp[j][j+i]) max_inc=dp[j][j+i];
            }
        }
    }
    cout<<(cur+max_inc)<<endl;
}