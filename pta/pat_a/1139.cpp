#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct Person {
    set<string> friends;
};
map<string, Person> contact;

bool sameg(string a, string b) { return a.size() == b.size(); }

string remove_single(string id) {
    if (id.size() >= 5) {
        return id.substr(1);
    }
    return id;
}

vector<pair<string, string>> fc(string a, string b) {
    vector<string> ff;
    for (auto it = contact[a].friends.begin(); it != contact[a].friends.end();
         it++) {
        if (sameg(a, *it) && *it != b) {
            ff.push_back(*it);
        }
    }
    vector<pair<string, string>> sf;
    for (int i = 0; i < ff.size(); i++) {
        for (auto it = contact[ff[i]].friends.begin();
             it != contact[ff[i]].friends.end(); it++) {
            if (sameg(a, b)) {
                if (a != *it && sameg(a, *it)) {
                    sf.push_back({ff[i], *it});
                }
            } else {
                if (a != *it && !sameg(a, *it)) {
                    sf.push_back({ff[i], *it});
                }
            }
        }
    }
    vector<pair<string, string>> result;
    for (int i = 0; i < sf.size(); i++) {
        if (contact[sf[i].second].friends.find(b) !=
            contact[sf[i].second].friends.end()) {
            result.push_back(
                {remove_single(sf[i].first), remove_single(sf[i].second)});
        }
    }
    sort(result.begin(), result.end());
    return result;
}

int main() {
    int n, m, k;
    char f1[6], f2[6];
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        scanf("%s %s", f1, f2);
        contact[f1].friends.insert(f2);
        contact[f2].friends.insert(f1);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        scanf("%s %s", f1, f2);
        vector<pair<string, string>> result = fc(f1, f2);
        printf("%lu\n", result.size());
        for (int j = 0; j < result.size(); j++) {
            printf("%s %s\n", result[j].first.c_str(),
                   result[j].second.c_str());
        }
    }
    return 0;
}