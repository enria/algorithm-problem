#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct Person {
    char id[9];
    int vg, tg;
    int type;
    bool operator<(Person p) {
        if (type == p.type) {
            if (vg + tg == p.vg + p.tg) {
                if (vg == p.vg) {
                    return strcmp(id, p.id) < 0;
                }
                return vg > p.vg;
            }
            return vg + tg > p.vg + p.tg;
        }
        return type < p.type;
    }
};

int main() {
    int n, q, h;
    cin >> n >> q >> h;
    vector<Person> ps;
    Person p;
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", p.id, &p.vg, &p.tg);
        if (p.vg >= q && p.tg >= q) {
            if (p.vg >= h && p.tg >= h)
                p.type = 1;
            else if (p.vg >= h)
                p.type = 2;
            else if (p.vg >= p.tg)
                p.type = 3;
            else
                p.type = 4;
            ps.push_back(p);
        }
    }
    sort(ps.begin(), ps.end());
    printf("%lu\n", ps.size());
    for (int i = 0; i < ps.size(); i++) {
        printf("%s %d %d\n", ps[i].id, ps[i].vg, ps[i].tg);
    }
    return 0;
}