#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct student {
    char id[7], name[9];
    int grade;
};

int main() {
    int n, c;
    cin >> n >> c;
    student ss[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", ss[i].id, ss[i].name, &ss[i].grade);
    }

    switch (c) {
        case 1:
            sort(ss, ss + n, [](student a, student b) -> bool {
                return strcmp(a.id, b.id) < 0;
            });
            break;
        case 2:
            sort(ss, ss + n, [](student a, student b) -> bool {
                int eq = strcmp(a.name, b.name);
                if (!eq) {
                    return strcmp(a.id, b.id) < 0;
                }
                return eq < 0;
            });
            break;
        case 3:
            sort(ss, ss + n, [](student a, student b) -> bool {
                if (a.grade == b.grade) {
                    return strcmp(a.id, b.id) < 0;
                }
                return a.grade < b.grade;
            });
            break;
    }

    for (int i = 0; i < n; i++) {
        printf("%s %s %d\n", ss[i].id, ss[i].name, ss[i].grade);
    }

    return 0;
}