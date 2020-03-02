#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<int, vector<string>> cour_stut;
    for (int i = 1; i <= k; i++) {
        cour_stut[i];
    }

    char _name[5];
    int _nc, _c;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", _name, &_nc);
        for (int j = 0; j < _nc; j++) {
            scanf("%d", &_c);
            cour_stut[_c].push_back(_name);
        }
    }
    for (auto it = cour_stut.begin(); it != cour_stut.end(); it++) {
        printf("%d %lu\n", (*it).first, (*it).second.size());
        sort((*it).second.begin(), (*it).second.end());
        for_each((*it).second.begin(), (*it).second.end(),
                 [](string name) { printf("%s\n", name.c_str()); });
    }

    return 0;
}