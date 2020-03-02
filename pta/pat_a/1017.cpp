#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;
struct customer {
    int ts;
    int spend;
};

#define MAX 100000

int main() {
    int n, k;
    cin >> n >> k;
    customer cs[n];
    for (int i = 0; i < n; i++) {
        int h, m, s;
        scanf("%02d:%02d:%02d %d", &h, &m, &s, &(cs[i].spend));
        cs[i].spend *= 60;
        cs[i].ts = h * 60 * 60 + m * 60 + s;
    }
    sort(cs, cs + n,
         [](customer a, customer b) -> bool { return a.ts < b.ts; });
    int finished[k];
    memset(finished, 0, sizeof(int) * k);
    int start = 8 * 60 * 60, end = 17 * 60 * 60;
    int waittime = 0;
    for (int i = 0; i < n; i++) {
        if (cs[i].ts > end) {
            n = i;
            break;
        }
        int _w = 0, avi = -1;
        for (int j = 0; j < k; j++) {
            if (finished[j] == 0) {
                avi = j;
                break;
            }
        }
        if (avi != -1) {
            if (cs[i].ts < start) {
                _w = start - cs[i].ts;
                finished[avi] = start + cs[i].spend;
            } else {
                finished[avi] = cs[i].spend + cs[i].ts;
            }
        } else {
            int min = *(min_element(finished, finished + k));
            for (int j = 0; j < k; j++) {
                if (finished[j] == min) {
                    if (avi == -1) {
                        avi = j;
                        if (min > cs[i].ts) {
                            _w = min - cs[i].ts;
                            finished[j] = cs[i].spend + min;
                        } else {
                            finished[j] = cs[i].spend + cs[i].ts;
                        }
                    } else {
                        finished[j] = 0;
                    }
                }
            }
        }
        waittime += _w;
    }
    printf("%.1f\n", waittime * 1.0 / 60 / n);
    return 0;
}