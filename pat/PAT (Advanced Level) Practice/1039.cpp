#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, k;
    map<string, vector<int>> stut_cour;
    cin >> n >> k;
    char name[5];
    for (int i = 0; i < k; i++) {
        int courid, sn;
        scanf("%d %d", &courid, &sn);
        for (int j = 0; j < sn; j++) {
            scanf("%s", name);
            stut_cour[name].push_back(courid);
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        printf("%s %lu", name, stut_cour[name].size());
        sort(stut_cour[name].begin(), stut_cour[name].end());
        for (auto j = stut_cour[name].begin(); j != stut_cour[name].end();
             j++) {
            printf(" %d",*j);
        }
        printf("\n");
    }
    return 0;
}