#include <algorithm>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <vector>

using namespace std;
// 0:title 1:author 2:keyword 3:publisher 4:year
map<string, vector<string>> searchIndex[5];

set<string> search(string query) {
    set<string> result;
    for (int i = 0; i < 5; i++) {
        vector<string> cur = searchIndex[i][query];
        result.insert(cur.begin(), cur.end());
    }
    return result;
}

void indexKeywords(string keywords, string id) {
    string temp;
    for (int i = 0; i < keywords.size(); i++) {
        if (keywords.at(i) == ' ') {
            searchIndex[2][temp].push_back(id);
            temp = "";
        } else {
            temp += keywords.at(i);
            if (i == keywords.size() - 1) {
                searchIndex[2][temp].push_back(id);
            }
        }
    }
}
// 0:title 1:author 2:keyword 3:publisher 4:year
int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        string id, title, author, keywords, publisher, year;
        getline(cin, id);
        getline(cin, title);
        getline(cin, author);
        getline(cin, keywords);
        getline(cin, publisher);
        getline(cin, year);
        searchIndex[0][title].push_back(id);
        searchIndex[1][author].push_back(id);
        indexKeywords(keywords, id);
        searchIndex[3][publisher].push_back(id);
        searchIndex[4][year].push_back(id);
    }
    int m;
    cin >> m;
    vector<pair<int, string>> querys;
    for (int i = 1, user; i <= m; i++) {
        string query;
        scanf("%d: ", &user);
        getline(cin, query);
        querys.push_back({user, query});
    }
    for (int i = 0; i < m; i++) {
        printf("%d: %s\n", querys[i].first, querys[i].second.c_str());
        set<string> result = search(querys[i].second);
        if (result.size()) {
            for (auto it = result.begin(); it != result.end(); it++) {
                printf("%s\n", it->c_str());
            }
        } else {
            printf("Not Found\n");
        }
    }
    return 0;
}