#include <iostream>

using namespace std;

struct Grade {
    string name = " ", id;
} grades[101];

int main() {
    int n, g1, g2;
    cin >> n;
    char _n[11], _id[11];
    for (int i = 0, _g; i < n; i++) {
        scanf("%s %s %d", _n, _id, &_g);
        grades[_g].name = _n;
        grades[_g].id = _id;
    }
    bool flag = false;
    cin >> g1 >> g2;
    for (int g = g2; g >= g1; g--) {
        if (grades[g].name != " ") {
            flag = true;
            printf("%s %s\n", grades[g].name.c_str(), grades[g].id.c_str());
        }
    }
    if (!flag) {
        printf("NONE\n");
    }

    return 0;
}