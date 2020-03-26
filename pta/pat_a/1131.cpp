#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Move {
    int line, to;
    Move(int a, int b) : line(a), to(b) {}
};

struct Station {
    bool visited = false;
    vector<Move> nbs;
} stations[10000];

struct Solution {
    int stops = 0, transfer = 0;
    vector<Move> moves;
    bool operator<(Solution sol) {
        if (stops == sol.stops) {
            return transfer < sol.transfer;
        }
        return stops < sol.stops;
    }
} best;

void dfs(int dest, int to, Solution sol) {
    if (to == dest) {
        if (sol < best) {
            best = sol;
        }
    } else {
        for (int i = 0; i < stations[to].nbs.size(); i++) {
            Move move = stations[to].nbs[i];
            if (!stations[move.to].visited) {
                Solution newSol = sol;
                newSol.stops += 1;
                if (newSol.moves.size() &&
                    move.line != newSol.moves.rbegin()->line) {
                    newSol.transfer++;
                }
                if (best < sol) {
                    continue;
                }
                newSol.moves.push_back(move);
                stations[move.to].visited = true;
                dfs(dest, move.to, newSol);
                stations[move.to].visited = false;
            }
        }
    }
}

int main() {
    int n, m, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int pre = -1, cur;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &cur);
            if (j != 0) {
                stations[pre].nbs.push_back({i, cur});
                stations[cur].nbs.push_back({i, pre});
            }
            pre = cur;
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        best.stops = 10000;
        Solution sol;
        int source, dest;
        scanf("%d %d", &source, &dest);
        dfs(dest, source, sol);
        printf("%d\n", best.stops);
        for (int j = 0; j < best.moves.size(); j++) {
            Move move = best.moves[j];
            if (j != best.moves.size() - 1 &&
                move.line == best.moves[j + 1].line) {
                continue;
            }
            printf("Take Line#%d from %04d to %04d.\n", move.line, source,
                   move.to);
            source = move.to;
        }
    }
    return 0;
}