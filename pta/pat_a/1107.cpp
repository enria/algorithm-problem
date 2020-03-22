#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, pair<int, set<int>> *> cache;  // hobby,num,hobbys
    for (int i = 0; i < n; i++) {
        int hs, h;
        scanf("%d:", &hs);
        int hsi[hs];
        set<pair<int, set<int>> *> match;
        for (int j = 0; j < hs; j++) {
            scanf("%d", &h);
            hsi[j] = h;
            if (cache[h]) {
                match.insert(cache[h]);
            }
        }
        pair<int, set<int>> *cur =
            (pair<int, set<int>> *)malloc(sizeof(pair<int, set<int>>));
        cur->first = 1, cur->second = set<int>(hsi, hsi + hs);
        if (match.size()) {
            for (auto it = match.begin(); it != match.end(); it++) {
                cur->first += (*it)->first;
                cur->second.insert((*it)->second.begin(), (*it)->second.end());
            }
        }
        for (auto jt = cur->second.begin(); jt != cur->second.end(); jt++) {
            cache[*jt] = cur;
        }
    }
    set<pair<int, set<int>> *> result;
    for (auto it = cache.begin(); it != cache.end(); it++) {
        result.insert(it->second);
    }
    vector<pair<int, set<int>> *> sort_result(result.begin(), result.end());
    sort(sort_result.begin(), sort_result.end(),
         [](pair<int, set<int>> *a, pair<int, set<int>> *b) -> bool {
             return a->first > b->first;
         });
    printf("%lu\n", sort_result.size());
    for (int i = 0; i < sort_result.size(); i++) {
        printf("%d", sort_result[i]->first);
        printf(i == sort_result.size() - 1 ? "\n" : " ");
    }

    return 0;
}