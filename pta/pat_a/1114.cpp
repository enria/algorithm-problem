#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

map<string,string> fathers;

string findRoot(string id) { //TODO ""的布尔值
    if(fathers[id]==""||fathers[id]==id) {
        fathers[id]=id;
        return id;
    } else {
        string root= findRoot(fathers[id]);
        fathers[id]=root;
        return root;
    }
}

struct Person {
    int sets,area;
};

struct Family {
    string id;
    int members;
    int sets,area;
};

map<string,Person> members;


int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        char id[5],member[5];
        scanf("%s",id);
        string root=findRoot(id);
        fathers[id]=root;
        for(int j=0; j<2; j++) {
            scanf("%s",member);
            if(strcmp(member,"-1")!=0) {//TODO 
                string mr=findRoot(member);
                fathers[mr]=root;
                members[member];//有的父母或儿子没有资产
            }
        }
        int ks;
        scanf("%d",&ks);
        for(int j=0; j<ks; j++) {
            scanf("%s",member);
            string mr=findRoot(member);
            fathers[mr]=root;
            members[member];//有的父母或儿子没有资产
        }
        int sets,area;
        scanf("%d %d",&sets,&area);
        members[id]= {sets,area};
    }
    map<string,Family> fams;
    for(auto it=members.begin(); it!=members.end(); it++) {
        string root=findRoot(it->first);
        if(fams[root].id==""||fams[root].id>it->first) {
            fams[root].id=it->first;
        }
        fams[root].members++;
        fams[root].sets+=it->second.sets;
        fams[root].area+=it->second.area;
    }
    vector<pair<string,Family>> sorted_fams(fams.begin(),fams.end());
    sort(sorted_fams.begin(),sorted_fams.end(),[](pair<string,Family> a,pair<string,Family> b)->bool{
        if((a.second.area*1.0/a.second.members)==(b.second.area*1.0/b.second.members)) {
            return a.second.id<b.second.id;
        }
        return (a.second.area*1.0/a.second.members)>(b.second.area*1.0/b.second.members);
    });
    printf("%d\n",sorted_fams.size());
    for(int i=0; i<sorted_fams.size(); i++) {
        Family f=sorted_fams[i].second;
        printf("%s %d %.3f %.3f\n",f.id.c_str(),f.members,f.sets*1.0/f.members,f.area*1.0/f.members);
    }
}
