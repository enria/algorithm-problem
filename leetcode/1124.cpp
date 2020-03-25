#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int m, n, s;
    map<string, bool> won;
    vector<string> forwards;
    vector<string> winners;
    cin >> m >> n >> s;
    for (int i = 0; i < m; i++) {
        char name[21];
        scanf("%s", name);
        forwards.push_back(name);
    }
    for (int i = s - 1; i < m;) {
        string name = forwards[i];
        if (won[name]) {
            i++;
        } else {
            winners.push_back(name);
            won[name] = true;
            i += n;
        }
    }
    if (winners.size()) {
        for (int i = 0; i < winners.size(); i++) {
            printf("%s\n", winners[i].c_str());
        }
    } else {
        printf("Keep going...\n");
    }

    return 0;
}