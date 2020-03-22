#include <iostream>
#include <vector>

using namespace std;

struct Move {
    int to;
    int length, time;
};

struct Node {
    bool visited = false;
    vector<Move> nbs;
} nodes[500];

// TODO 结构体，全局变量，局部变量初始值
// TODO 使用sol全局变量赋值两个最优解
struct Solution {
    long length = -1, time;
    vector<int> nodes;
    bool operator==(Solution s) { return length == s.length && time == s.time; }
} shortest, fastest;

int N, M, S, D;

void dfs(int to, Solution sol) {
    if (to == D) {
        if (shortest.length == -1 || shortest.length > sol.length ||
            (shortest.length == sol.length && shortest.time > sol.time)) {
            shortest = sol;
        }
        if (fastest.length == -1 || fastest.time > sol.time ||
            (fastest.time == sol.time && fastest.length > sol.length)) {
            fastest = sol;
        }
        return;
    }
    for (int i = 0; i < nodes[to].nbs.size(); i++) {
        Move move = nodes[to].nbs[i];
        if (!nodes[move.to].visited) {
            Solution newSol = sol;
            newSol.length += move.length;
            newSol.time += move.time;
            newSol.nodes.push_back(move.to);
            nodes[move.to].visited = true;
            dfs(move.to, newSol);
            nodes[move.to].visited = false;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int v1, v2, oneway, length, time;
        scanf("%d %d %d %d %d", &v1, &v2, &oneway, &length, &time);
        nodes[v1].nbs.push_back({v2, length, time});
        if (!oneway) {
            nodes[v2].nbs.push_back({v1, length, time});
        }
    }
    cin >> S >> D;
    Solution sol;
    sol.length = 0, sol.time = 0, sol.nodes.push_back(S);
    dfs(S, sol);
    if (fastest == shortest) {
        printf("Distance = %ld; Time = %ld:", fastest.length, fastest.time);
        for (int i = 0; i < fastest.nodes.size(); i++) {
            printf(" %d", fastest.nodes[i]);
            printf(i == fastest.nodes.size() - 1 ? "\n" : " ->");
        }
    } else {
        printf("Distance = %ld:", shortest.length);
        for (int i = 0; i < shortest.nodes.size(); i++) {
            printf(" %d", shortest.nodes[i]);
            printf(i == shortest.nodes.size() - 1 ? "\n" : " ->");
        }
        printf("Time = %ld:", fastest.time);
        for (int i = 0; i < fastest.nodes.size(); i++) {
            printf(" %d", fastest.nodes[i]);
            printf(i == fastest.nodes.size() - 1 ? "\n" : " ->");
        }
    }
    return 0;
}