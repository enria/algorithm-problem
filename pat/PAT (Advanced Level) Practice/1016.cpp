#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct call {
    int M1 = 0, d1, h1, m1;
    int M2 = 0, d2, h2, m2;
};

struct record {
    string name;
    int M, d, h, m;
    string turn;
    string raw;
};

int cost[24], day_cost = -1;

pair<int, int> call_cost(call c) {
    int ms = 0, cc = 0;
    if (day_cost == -1) {
        day_cost = 0;
        for (int i = 0; i < 24; i++) {
            day_cost += cost[i] * 60;
        }
    }
    if (c.d2 - c.d1 > 1) {
        cc = (c.d2 - c.d1 - 1) * day_cost;
        ms += 24 * 60 * (c.d2 - c.d1 - 1);
    }
    if (c.d2 != c.d1) {
        cc += cost[c.h1] * (60 - c.m1);
        ms += 60 - c.m1;
        for (int i = c.h1 + 1; i < 24; i++) {
            cc += cost[i] * 60;
            ms += 60;
        }
        for (int i = 0; i < c.h2; i++) {
            cc += cost[i] * 60;
            ms += 60;
        }
        cc += cost[c.h2] * c.m2;
        ms += c.m2;
    } else {
        if (c.h1 != c.h2) {
            cc += cost[c.h1] * (60 - c.m1);
            ms += 60 - c.m1;
            for (int i = c.h1 + 1; i < c.h2; i++) {
                cc += cost[i] * 60;
                ms += 60;
            }
            cc += cost[c.h2] * c.m2;
            ms += c.m2;
        } else {
            cc += cost[c.h1] * (c.m2 - c.m1);
            ms += c.m2 - c.m1;
        }
    }
    return pair<int, int>(ms, cc);
}

int main() {
    for (int i = 0; i < 24; i++) {
        cin >> cost[i];
    }

    int n;
    cin >> n;
    map<string, vector<call>> list;
    record _calls[n];
    for (int i = 0; i < n; i++) {
        string name, turn;
        int M, d, h, m;
        cin >> name;
        scanf("%02d:%02d:%02d:%02d", &M, &d, &h, &m);
        cin >> turn;
        _calls[i] = {name, M, d, h, m, turn};
        char _raw[9];
        sprintf(_raw, "%02d:%02d:%02d", d, h, m);
        _calls[i].raw = _raw;
    }

    sort(_calls, _calls + n,
         [](record a, record b) -> bool { return a.raw.compare(b.raw)<0; });

    for (int i = 0; i < n; i++) {
        call *pre = 0;
        int size;
        string name = _calls[i].name, turn = _calls[i].turn;
        call c;
        if (list.count(name)) {  // TODO map直接取值会怎样？
            size = list[name].size();
            if (list[name].size()) pre = &(list[name][size - 1]);
        } else {
            vector<call> v;
            list[name] = v;
            size = 0;
        }
        if (turn == "on-line") {
            c.M1 = _calls[i].M, c.d1 = _calls[i].d, c.h1 = _calls[i].h,
            c.m1 = _calls[i].m;
            if (!pre || pre->M2) {
                list[name].push_back(c);
            } else {
                list[name][size - 1] = c;
            }
        } else {
            if (pre != NULL && pre->M2 == 0) {
                pre->M2 = _calls[i].M, pre->d2 = _calls[i].d,
                pre->h2 = _calls[i].h, pre->m2 = _calls[i].m;
            }
        }
    }

    for (auto it = list.begin(); it != list.end(); it++) {
        string name = it->first;
        vector<call> calls = it->second;
        if(calls.size()==0||!calls[0].M2){
            continue;
        }
        printf("%s %02d\n", name.c_str(), calls[0].M1);
        int total = 0;
        for (int i = 0; i < calls.size(); i++) {
            if (i == calls.size() - 1) {
                if (calls[i].M2 == 0) {
                    break;
                }
            }
            call c = calls[i];
            pair<int, int> cc = call_cost(c);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", c.d1, c.h1, c.m1,
                   c.d2, c.h2, c.m2, cc.first, cc.second / 100.0);
            total += cc.second;
        }
        printf("Total amount: $%.2f\n", total / 100.0);
    }

    return 0;
}