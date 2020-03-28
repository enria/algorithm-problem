#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Grade {
    string name;
    int program, midg = -1, finalg = -1;
    int gf;
    bool qualified() {
        if (program < 200) return false;
        return gf >= 60;
    }

    void calGf() {
        if (midg > finalg) {
            gf = round(midg * 0.4 + (finalg == -1 ? 0 : finalg) * 0.6);
        } else {
            gf = finalg;
        }
    }

    bool operator<(Grade g) {
        if (g.gf == gf) {
            return name < g.name;
        }
        return gf > g.gf;
    }
};

int main() {
    int P, M, N;
    cin >> P >> M >> N;
    char name[21];
    map<string, Grade> grades;
    for (int i = 0; i < P; i++) {
        scanf("%s", name);
        scanf("%d", &grades[name].program);
        grades[name].name = name;
    }
    for (int i = 0; i < M; i++) {
        scanf("%s", name);
        scanf("%d", &grades[name].midg);
    }
    for (int i = 0; i < N; i++) {
        scanf("%s", name);
        scanf("%d", &grades[name].finalg);
    }
    vector<Grade> grade_rank;
    for (auto it = grades.begin(); it != grades.end(); it++) {
        it->second.calGf();
        if (it->second.qualified()) {
            grade_rank.push_back(it->second);
        }
    }
    sort(grade_rank.begin(), grade_rank.end());
    for (int i = 0; i < grade_rank.size(); i++) {
        Grade g = grade_rank[i];
        printf("%s %d %d %d %d\n", g.name.c_str(), g.program, g.midg, g.finalg,
               (int)g.gf);
    }

    return 0;
}