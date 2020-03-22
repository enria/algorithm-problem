#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int k;
    cin>>k;
    string s;

    cin>>s;
    int cnt=0;
    char pre='!';
    map<char,int> repeat_order;
    for(int i=0; i<s.size(); i++) {
        if(s.at(i)==pre) {
            cnt++;
            if(cnt==k) {
                if(!repeat_order[pre]) {
                    repeat_order[pre]=repeat_order.size()+1;
                }
                pre='!';
                cnt=0;
            }
        } else {
            if(cnt==k) {
                if(!repeat_order[pre]) {
                    repeat_order[pre]=repeat_order.size()+1;

                }
            } else {
                repeat_order[pre]=-1;
            }
            cnt=1;
            pre=s.at(i);
        }
    }
    if(cnt!=k)
        repeat_order[pre]=-1;
    vector<pair<char,int>> repeats;
    
    for(auto it=repeat_order.begin(); it!=repeat_order.end(); it++) {
        if(it->second>0) {
            repeats.push_back({it->first,it->second});
        }
    }
    sort(repeats.begin(),repeats.end(),[](pair<char,int> a,pair<char,int> b)->bool{return a.second<b.second;});
    for(int i=0; i<repeats.size(); i++) {
        printf("%c",repeats[i].first);
    }
    printf("\n");
    for(int i=0; i<s.size();) {
        printf("%c",s.at(i));
        if(repeat_order[s.at(i)]>0) {
            i+=k;
        } else {
            i++;
        }
    }
}
