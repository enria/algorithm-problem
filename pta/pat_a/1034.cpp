#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, string> father;  //并查集

string findf(string name) {
    string f;
    if (father[name] == "" || father[name] == name) {
        f = name;
    } else {
        f = findf(father[name]);
    }
    father[name] = f;
    return f;
}

int main() {
    int n, k;
    cin >> n >> k;
    char nm1[4], nm2[4];
    int w;
    map<string, int> rws;
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", nm1, nm2, &w);
        string f1 = findf(nm1), f2 = findf(nm2);
        father[f2] = f1;  //这句特别重要，是并查集的精髓
        rws[nm1] += w, rws[nm2] += w;
    }
    map<string, map<string, int>> gangs;
    for (auto it = father.begin(); it != father.end(); it++) {
        string f = findf(it->first);  //使根结点统一
        gangs[f][it->first] = rws[it->first];
    }
    vector<pair<string, int>> result;
    for (auto it = gangs.begin(); it != gangs.end(); it++) {
        if (it->second.size() <= 2) continue;
        int tw = 0, maxw = -1;
        string maxname;
        for (auto it2 = gangs[it->first].begin(); it2 != gangs[it->first].end();
             it2++) {
            tw += it2->second;
            if (maxw == -1 || it2->second > maxw) {
                maxw = it2->second;
                maxname = it2->first;
            }
        }
        if (tw / 2 > k) {
            result.push_back(pair<string, int>(maxname, it->second.size()));
        }
    }
    sort(result.begin(), result.end(),
         [](pair<string, int> a, pair<string, int> b) -> bool {
             return a.first < b.first;
         });
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        printf("%s %d\n", result[i].first.c_str(), result[i].second);
    }
    return 0;
}