#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define WM 1000
#define MAX 65535

int str_to_ms(int h, int m) { return (h - 8) * 60 + m; }
pair<int, int> ms_to_str(int m) { return pair<int, int>((m / 60) + 8, m % 60); }

int main() {
    int maxm = str_to_ms(17, 0);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    queue<pair<int, int>> windows[n];
    int wfirst[n];
    int ft[k], tt = 0;
    memset(ft, 0, sizeof(int) * k);
    memset(wfirst,0,sizeof(int)*n);
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        if (tt >= maxm) {
            continue;
        }
        int cw = -1, cm = WM;
        for (int j = 0; j < n; j++) {
            queue<pair<int, int>> w = windows[j];
            if (w.size() < cm && w.size() < m) {
                cw = j, cm = w.size();
            }
        }
        if (cw == -1) {  //所有队列都满，消除队首
            int mt = *(min_element(wfirst, wfirst + n));
            tt += mt;
            for (int j = 0; j < n; j++) {
                if (wfirst[j] == mt) {
                    ft[windows[j].front().first] = tt;
                    windows[j].pop();
                    if (windows[j].size()) {
                        wfirst[j] = windows[j].front().second;
                    } else {
                        wfirst[j] = MAX;
                    }
                    if (cw == -1) {
                        cw = j;
                        cm=windows[j].size();
                    }
                } else {
                    wfirst[j] -= mt;
                }
            }
        }
        if (tt < maxm) {
            //加人到队列
            windows[cw].push(pair<int, int>(i, t));
            if (cm == 0) {
                wfirst[cw] = t;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        if (!windows[j].size()) {
            continue;
        }
        int _tt = tt;
        if (windows[j].front().second != wfirst[j]) {
            ft[windows[j].front().first] = _tt + wfirst[j];
            _tt += wfirst[j];
            windows[j].pop();
        }
        while (_tt < maxm && windows[j].size()) {
            pair<int,int> c= windows[j].front();
            ft[c.first]=_tt+c.second;
            _tt+=c.second;
            windows[j].pop();
        }
    }


    //BUG 超时问题
    // while (1) {
    //     if (tt >= maxm) {
    //         for (int i = 0; i < n; i++) {
    //             if (!windows[i].empty()) {
    //                 if (wfirst[i] != windows[i].front().second) {
    //                     ft[windows[i].front().first] = tt + wfirst[i];
    //                 }
    //             }
    //         }
    //         break;
    //     }
    //     int mt = *(min_element(wfirst, wfirst + n));
    //     tt += mt;
    //     bool ept = true;
    //     for (int j = 0; j < n; j++) {
    //         if (windows[j].empty()) {
    //             continue;
    //         }
    //         if (wfirst[j] == mt) {
    //             ft[windows[j].front().first] = tt;
    //             windows[j].pop();
    //             if (windows[j].size()) {
    //                 ept = false;
    //                 wfirst[j] = windows[j].front().second;
    //             } else {
    //                 wfirst[j] = MAX;
    //             }
    //         } else {
    //             wfirst[j] -= mt;
    //             ept = false;
    //         }
    //     }
    //     if (ept) break;
    // }

    for (int i = 0; i < q; i++) {
        int _q;
        cin >> _q;
        if (ft[_q - 1]) {
            pair<int, int> _ft = ms_to_str(ft[_q - 1]);
            printf("%02d:%02d\n", _ft.first, _ft.second);
        } else {
            printf("Sorry\n");
        }
    }

    return 0;
}