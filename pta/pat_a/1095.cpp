#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Record {
    char plate[7];
    int h, m, s;
    int io = 0;  // 1是进，0是出
    bool operator<(Record r) {
        return h * 3600 + m * 60 + s < r.h * 3600 + r.m * 60 + r.s;
    }
    int operator-(Record r) {
        return h * 3600 + m * 60 + s - (r.h * 3600 + r.m * 60 + r.s);
    }
};

struct Query {
    int h, m, s;
    int state;
};

bool le(Query q, Record r) {
    return q.h * 3600 + q.m * 60 + q.s < r.h * 3600 + r.m * 60 + r.s;
}

string timets(int seconds) {
    int h, m, s;
    h = seconds / 3600, seconds = seconds % 3600;
    m = seconds / 60, seconds = seconds % 60;
    s = seconds;
    char ts[9];
    sprintf(ts, "%02d:%02d:%02d", h, m, s);
    string tss = ts;
    return tss;
}

int main() {
    int n, k;
    cin >> n >> k;
    Record records[n];
    Query querys[k];
    char io[4];
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d", records[i].plate, &records[i].h, &records[i].m,
              &records[i].s);
        scanf("%s", io);
        records[i].io = io[0] == 'i' ? 1 : 0;
    }
    for (int i = 0; i < k; i++) {
        scanf("%d:%d:%d", &querys[i].h, &querys[i].m, &querys[i].s);
    }

    sort(records, records + n);
    map<string, Record> cache;
    map<string, vector<Record>> car_states;
    for (int i = 0; i < n; i++) {
        string plate = records[i].plate;
        int oio = car_states[plate].size()
                      ? car_states[plate][car_states[plate].size() - 1].io
                      : 0;
        int nio = records[i].io;
        if (oio == 1 && nio == 1) {  //清理数据
            car_states[plate][car_states[plate].size() - 1] = records[i];
            continue;
        }
        if (oio == 0 && nio == 0) {  //清理数据
            continue;
        }
        car_states[plate].push_back(records[i]);
    }
    vector<Record> validrs;
    map<string, int> parking_time;
    for (auto it = car_states.begin(); it != car_states.end(); it++) {
        if ((*it).second.size() > 1) {
            if (it->second[it->second.size() - 1].io == 1) {  //丢掉最后一个进
                validrs.insert(validrs.end(), it->second.begin(),
                               it->second.end() - 1);
            } else {
                validrs.insert(validrs.end(), it->second.begin(),
                               it->second.end());
            }
            parking_time[it->first] = 0;
        }
    }
    sort(validrs.begin(), validrs.end());
    int state = 0, qi = 0, pt;
    for (int i = 0; i < validrs.size(); i++) {
        string plate = validrs[i].plate;
        int nio = validrs[i].io;
        for (; qi < k && le(querys[qi], validrs[i]); qi++) {  //状态改变
            querys[qi].state = state;
        }
        if (nio == 1) {
            cache[plate] = validrs[i];
            state++;
        } else {
            pt = validrs[i] - cache[plate];
            parking_time[plate] += pt;
            cache[plate] = validrs[i];
            state--;
        }
    }
    for (; qi < k; qi++) {
        querys[qi].state = state;
    }

    for (int i = 0; i < k; i++) {
        printf("%d\n", querys[i].state);
    }

    vector<pair<string, int>> max_plates(parking_time.begin(),
                                         parking_time.end());
    sort(max_plates.begin(), max_plates.end(),
         [](pair<string, int> a, pair<string, int> b) -> bool {
             if (a.second == b.second) {
                 return a.first.compare(b.first) < 0;
             }
             return a.second > b.second;
         });
    int max_time = max_plates[0].second;
    for (int i = 0; i < max_plates.size(); i++) {
        if (max_plates[i].second == max_time) {
            printf("%s ", max_plates[i].first.c_str());
        }
    }
    cout << timets(max_time) << endl;
    return 0;
}