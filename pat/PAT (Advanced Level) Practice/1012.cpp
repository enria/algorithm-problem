#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

char FLAGS[] = {'C', 'M', 'E', 'A'};

struct Grade {
    string id;
    int c, m, e;
    float average;
    int ranks[4];
};

int main() {
    int n, m;
    cin >> n >> m;
    Grade list[n];
    map<string,Grade> c;
    for (int i = 0; i < n; i++) {
        Grade g = list[i];
        cin >> g.id >> g.c >> g.m >> g.e;
        g.average = (g.c + g.m + g.e) / 3;
        list[i] = g;
        c[g.id]=g;
        cout << &g<<" "<<&list[i]<<" "<<&c[g.id] << endl;
    }

    sort(list, list + n, [](Grade s1, Grade s2) { return s1.c > s2.c; });
    for (int i = 0; i < n; i++) {
        list[i].ranks[0] = i + 1;
    }

    sort(list, list + n, [](Grade s1, Grade s2) { return s1.m > s2.m; });
    for (int i = 0; i < n; i++) {
        list[i].ranks[1] = i + 1;
    }

    sort(list, list + n, [](Grade s1, Grade s2) { return s1.e > s2.e; });
    for (int i = 0; i < n; i++) {
        list[i].ranks[2] = i + 1;
    }

    sort(list, list + n,
         [](Grade s1, Grade s2) { return s1.average > s2.average; });
    for (int i = 0; i < n; i++) {
        list[i].ranks[3] = i + 1;
    }
    string searchs[m];
    for (int i = 0; i < m; i++) {
        cin >> searchs[i];
    }

    map<string, int> index;
    for (int i = 0; i < n; i++) {
        index[list[i].id] = i;
    }

    for (int i = 0; i < m; i++) {
        string id = searchs[i];
        if (index.count(id)) {
            Grade g = list[index[id]];
            int max = 3;
            for (int j = 0; j < 3; j++) {
                if (g.ranks[j] < g.ranks[max]) {
                    max = j;
                }
            }
            printf("%d %c\n", g.ranks[max], FLAGS[max]);
        } else {
            printf("N/A\n");
        }
    }

    return 0;
}