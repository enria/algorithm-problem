#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
struct Person {
    char name[9];
    int age, worth;
    bool operator<(Person n) {
        if (n.worth == worth) {
            if (n.age == age) {
                return strcmp(name, n.name) < 0;
            }
            return age < n.age;
        }
        return worth > n.worth;
    }
};
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    map<int, vector<Person>> dat;
    for (int i = 0; i < n; i++) {
        Person p;
        scanf("%s %d %d", p.name, &p.age, &p.worth);
        dat[p.age].push_back(p);
    }
    for (auto it = dat.begin(); it != dat.end(); it++) {
        sort((*it).second.begin(), (*it).second.end());
    }
    int index[201];
    for (int i = 0; i < k; i++) {
        memset(index, 0, sizeof(index));
        int max, start, end;
        scanf("%d %d %d", &max, &start, &end);
        vector<Person> inrange;

        bool add = true;
        while (add && inrange.size() < max) {
            int first = -1;
            add = false;
            for (int j = start; j <= end; j++) {
                if (index[j] < dat[j].size()) {
                    if (first == -1 ||
                        dat[j][index[j]] < dat[first][index[first]]) {
                        first = j;
                    }
                }
            }
            if (first != -1) {
                add = true;
                inrange.push_back(dat[first][index[first]]);
                index[first]++;
            }
        }

        printf("Case #%d:\n", i + 1);
        if (inrange.size()) {
            sort(inrange.begin(), inrange.end());
            for (int j = 0; j < max && j < inrange.size(); j++) {
                printf("%s %d %d\n", inrange[j].name, inrange[j].age,
                       inrange[j].worth);
            }

        } else {
            printf("None\n");
        }
    }

    return 0;
}