#include <iostream>
#include <map>
#include <vector>

#define DEST "ROM"

using namespace std;

struct Move {
    int to, cost;
};

struct City {
    string name;
    int happiness;
    vector<Move> neighbors;
    bool visited;
} cities[200];  // TODO 试试只用map

map<string, int> index;

int desti;
struct Solution {
    int cost = -1, happiness = 0, visited = 0;
    int same_cost = 1;
    vector<string> routes;
} best;
void dfs(int from, int to, Solution cur) {
    cur.happiness += cities[to].happiness;
    cur.visited += 1;
    cur.routes.push_back(cities[to].name);
    if (to == desti) {
        if (cur.cost < best.cost || best.cost == -1) {
            best = cur;
        } else if (cur.cost == best.cost) {
            int same_cost = best.same_cost + 1;
            if (cur.happiness > best.happiness) {
                best = cur;
            } else if (cur.happiness == best.happiness) {
                if (cur.visited < best.visited) {
                    best = cur;
                }
            }
            best.same_cost = same_cost;
        }
    } else {
        for (int i = 0; i < cities[to].neighbors.size(); i++) {
            Move move = cities[to].neighbors[i];
            if (!cities[move.to].visited) {
                cur.cost += move.cost;
                if (best.cost == -1 || cur.cost <= best.cost) {  //剪枝
                    cities[move.to].visited = true;
                    dfs(to, move.to, cur);
                    cities[move.to].visited = false;
                }
                cur.cost -= move.cost;
            }
        }
    }
}

int main() {
    int n, k;
    string from, to = "ROM";
    cin >> n >> k >> from;
    index[from] = 0;
    cities[0].name = from, cities[0].visited = true;
    char city1[4], city2[4];
    for (int i = 1; i < n; i++) {
        scanf("%s", city1);
        index[city1] = i;
        scanf("%d", &cities[i].happiness);
        cities[i].name = city1;
        if (DEST == string(city1)) {
            desti = i;
        }
    }
    int cost;
    for (int i = 0; i < k; i++) {
        scanf("%s %s %d", city1, city2, &cost);
        int ci1 = index[city1], ci2 = index[city2];
        cities[ci1].neighbors.push_back(Move{ci2, cost});
        cities[ci2].neighbors.push_back(Move{ci1, cost});
    }
    Solution solu;
    solu.cost = 0;
    dfs(-1, 0, solu);
    printf("%d %d %d %d\n", best.same_cost, best.cost, best.happiness,
           best.happiness / (best.visited - 1));
    for (int i = 0; i < best.routes.size(); i++) {
        printf("%s", best.routes[i].c_str());
        printf(i == best.routes.size() - 1 ? "\n" : "->");
    }
    return 0;
}