#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ppair {
    string at;
    int m, v;
    int p, n;
};

ppair *pairs;
int *vipTables;
void assign() {}

bool cat(ppair a, ppair b) { return a.at < b.at; }

int main() {
    int n;
    cin >> n;
    pairs = (ppair *)malloc(sizeof(ppair) * n);
    for (int i = 0; i < n; i++) {
        ppair p;
        cin >> p.at >> p.m >> p.v;
        pairs[i] = p;
    }
    sort(pairs, pairs + n, cat);
    int k, m;
    cin >> k >> m;
    vipTables = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        int mi;
        cin >> mi;
        vipTables[mi - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << pairs[i].at << endl;
    }

    return 0;
}