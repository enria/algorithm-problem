#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Institution {
    string code;
    int sb, sa, st;
    int testee;
    int tws;
    bool operator<(Institution i) {
        if (tws == i.tws) {
            if (testee == i.testee) {
                return code < i.code;
            }
            return testee < i.testee;
        }
        return tws > i.tws;
    }
    void calTws() { tws = sb / 1.5 + sa + st * 1.5; }
};

void lower(char *code) {
    for (int i = 0; code[i]; i++) {
        if (code[i] >= 'A' && code[i] <= 'Z') {
            code[i] -= 'A' - 'a';
        }
    }
}

int main() {
    map<string, Institution> insts;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char id[7], code[7];
        int score;
        scanf("%s %d %s", id, &score, code);
        lower(code);
        switch (id[0]) {
            case 'B':
                insts[code].sb += score;
                break;
            case 'A':
                insts[code].sa += score;
                break;
            case 'T':
                insts[code].st += score;
                break;
            default:
                break;
        }
        insts[code].testee++;
    }
    vector<Institution> insts_rank;
    for (auto it = insts.begin(); it != insts.end(); it++) {
        it->second.calTws();
        it->second.code = it->first;
        insts_rank.push_back(it->second);
    }
    sort(insts_rank.begin(), insts_rank.end());
    printf("%lu\n", insts_rank.size());
    int rank = 1;
    for (int i = 0; i < insts_rank.size(); i++) {
        Institution cur = insts_rank[i];
        if (i != 0 && cur.tws != insts_rank[i - 1].tws) {
            rank = i + 1;
        }
        printf("%d %s %d %d\n", rank, cur.code.c_str(), cur.tws, cur.testee);
    }

    return 0;
}