#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> states;

pair<int, int> find_wolf() {
    pair<int, int> best = {100, 100};
    for (int i = 1; i < states.size(); i++) {
        for (int j = i + 1; j < states.size(); j++) {
            vector<int> wolfs;
            int ss[states.size()] = {0};
            bool sol = true;
            for (int k = 1; k < states.size(); k++) {
                int state = (k == i || k == j) ? -states[k] : states[k];
                int chs = state / abs(state);
                if (ss[abs(state)] && ss[abs(state)] != chs) {
                    sol = false;
                    break;
                }
                ss[abs(state)] = chs;
            }
            if (!sol) continue;
            for (int k = 1; k < states.size() && wolfs.size() <= 2; k++) {
                if (ss[k] == -1) {
                    wolfs.push_back(k);
                }
            }
            for (int k = 1; k < states.size() && wolfs.size() < 2; k++) {
                if (ss[k] == 0) {
                    wolfs.push_back(k);
                }
            }
            if (wolfs.size() == 2) {
                sort(wolfs.begin(), wolfs.end());
                pair<int, int> temp = {wolfs[0], wolfs[1]};
                if (temp.first == i && temp.second == j) continue;
                if (temp.first != i && temp.second != j) continue;
                if (temp < best) {
                    best = temp;
                }
            }
        }
    }
    return best;
}

int main() {
    int n;
    cin >> n;
    states.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &states[i]);
    }
    pair<int, int> result = find_wolf();
    if (result.first == result.second) {
        printf("No Solution\n");
    } else {
        printf("%d %d\n", result.first, result.second);
    }

    return 0;
}