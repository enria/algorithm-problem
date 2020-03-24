#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    map<int, int> married;
    for (int i = 0; i < n; i++) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        married[c1] = c2;
        married[c2] = c1;
    }
    cin >> m;
    vector<int> single;
    map<int, bool> attend;
    for (int i = 0; i < m; i++) {
        int c;
        scanf("%d", &c);
        attend[c] = true;
    }
    for (auto it = attend.begin(); it != attend.end(); it++) {
        if (!(married.count(it->first) && attend[married[it->first]])) {
            single.push_back(it->first);
        }
    }

    printf("%lu\n", single.size());
    for (int i = 0; i < single.size(); i++) {
        printf("%05d", single[i]);
        printf(i == single.size() - 1 ? "\n" : " ");
    }

    return 0;
}