#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Appliance {
    int index;
    int ge, gi;
    float fg;
    vector<int> schools;
    bool operator<(Appliance a) {
        if (a.fg == fg) {
            return ge > a.ge;
        }
        return fg > a.fg;
    }
    bool operator==(Appliance a) { return fg == a.fg && a.ge == ge; }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int quota[m];
    Appliance apps[n];
    for (int i = 0; i < m; i++) {
        scanf("%d", quota + i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &apps[i].ge, &apps[i].gi);
        for (int j = 0, si; j < k; j++) {
            scanf("%d", &si);
            apps[i].schools.push_back(si);
        }
        apps[i].index = i;
        apps[i].fg = (apps[i].ge + apps[i].gi) / 2.0;
    }
    sort(apps, apps + n);
    map<int, vector<int>> admitted;
    for (int i = 0; i < n; i++) {
        for (int j = 0, si, ss; j < k; j++) {
            si = apps[i].schools[j];
            ss = admitted[si].size();
            if (admitted[si].size() < quota[si]) {
                admitted[si].push_back(i);
                break;
            } else if (ss && apps[admitted[si][ss - 1]] == apps[i]) {
                admitted[si].push_back(i);
                break;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        vector<int> index;
        for (int j = 0; j < admitted[i].size(); j++) {
            index.push_back(apps[admitted[i][j]].index);  //一定要搞清楚索引问题
        }
        sort(index.begin(), index.end());
        for (int j = 0; j < index.size(); j++) {
            if (j != 0) printf(" ");
            printf("%d", index[j]);
        }
        printf("\n");
    }
    return 0;
}