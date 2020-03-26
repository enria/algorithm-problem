#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
int times[50001];
pair<int, int> points[50001];

bool comp(int aid, int acnt, int bid, int bcnt) {
    if (acnt == bcnt) {
        return aid < bid;
    }
    return acnt > bcnt;
}

int main() {
    int n, k;
    cin >> n >> k;
    int head = 0, tail = 0;
    points[head].second = -1;
    for (int i = 0; i < n; i++) {
        vector<int> rs;
        int j = 0;
        int cur = points[head].second;
        while (cur > -1 && j < k) {
            rs.push_back(cur);
            cur = points[cur].second;
            j++;
        }
        int id;
        scanf("%d", &id);
        if (rs.size()) {
            printf("%d:", id);
            for (j = 0; j < rs.size(); j++) {
                printf(" %d", rs[j]);
            }
            printf("\n");
        }
        if (times[id]) {
            times[id]++;
        } else {
            times[id]++;
            points[id] = {tail, -1};
            points[tail].second = id;
            tail = id;
        }
        while (points[id].first != head) {
            int pre = points[id].first, next = points[id].second;
            if (comp(id, times[id], pre, times[pre])) {
                points[points[pre].first].second = id;
                points[id] = {points[pre].first, pre};
                points[pre] = {id, next};
                if (next > -1) {
                    points[next].first = pre;
                } else {
                    tail = pre;
                }
            } else {
                break;
            }
        }
    }
    return 0;
}