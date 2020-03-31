#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct Grade {
    string cardN;
    int score;
    Grade(string c, int s) : cardN(c), score(s) {}
    bool operator<(const Grade b) const {
        if (score == b.score) {
            return cardN < b.cardN;
        }
        return score > b.score;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    map<char, set<Grade>> levelIndex;
    map<string, pair<int, int>> siteIndex;
    map<string, map<string, int>> dateIndex;
    map<string, vector<pair<string, int>>> dateSortIndex;
    char temp[15];
    for (int i = 0; i < n; i++) {
        int score;
        scanf("%s %d", temp, &score);
        string cardN = temp;
        string site = cardN.substr(1, 3);
        levelIndex[cardN[0]].insert({cardN,score});
        siteIndex[site].first++, siteIndex[site].second += score;
        dateIndex[cardN.substr(4, 6)][site]++;
    }
    for (auto it = dateIndex.begin(); it != dateIndex.end(); it++) {
        dateSortIndex[it->first].insert(dateSortIndex[it->first].begin(),
                                        it->second.begin(), it->second.end());
        sort(dateSortIndex[it->first].begin(), dateSortIndex[it->first].end(),
             [](pair<string, int> a, pair<string, int> b) -> bool {
                 if (a.second == b.second) {
                     return a.first < b.first;
                 }
                 return a.second > b.second;
             });
    }

    for (int i = 0; i < m; i++) {
        int type;
        char input[7];
        scanf("%d %s", &type, input);
        printf("Case %d: %d %s\n", i + 1, type, input);
        switch (type) {
            case 1:
                if (levelIndex[input[0]].size()) {
                    for (auto it = levelIndex[input[0]].begin();
                         it != levelIndex[input[0]].end(); it++) {
                        printf("%s %d\n", it->cardN.c_str(), it->score);
                    }
                } else {
                    printf("NA\n");
                }

                break;
            case 2:
                if (siteIndex[input].first) {
                    printf("%d %d\n", siteIndex[input].first,
                           siteIndex[input].second);
                } else {
                    printf("NA\n");
                }
                break;
            case 3:
                if (dateSortIndex[input].size()) {
                    for (auto it = dateSortIndex[input].begin();
                         it != dateSortIndex[input].end(); it++) {
                        printf("%s %d\n", it->first.c_str(), it->second);
                    }
                } else {
                    printf("NA\n");
                }
                break;
            default:
                break;
        }
    }

    return 0;
}