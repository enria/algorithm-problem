#include <iostream>
#define MAX 65535
#include <string.h>
using namespace std;

int **mm;
int *ms;
int *na;
int n;

int dj(int s, int e) {
    int used[n], cur = s, dist[n];
    int rd[n][2];
    
    memset(used,0,sizeof(used));
    used[cur] = 1;
    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        dist[i] = mm[s][i];
    }
    while (cur != e) {
        int _cn = -1, _cd = MAX;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            if (dist[cur] + mm[cur][i] < dist[i]) {
                dist[i] = dist[cur] + mm[cur][i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            if (dist[i] < _cd) {
                _cd = dist[i];
                _cn = i;
            }
        }
        used[_cn] = 1;
        cur = _cn;
        cout << cur << endl;
    }
    return dist[e];
}

int main() {
    int m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    na = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> na[i];
    }
    mm = new int *[n];
    for (int i = 0; i < n; i++) {
        mm[i] = new int[n];
        for(int j=0;j<n;j++){
            mm[i][j]=MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        int ct1, ct2, cs;
        cin >> ct1 >> ct2 >> cs;
        mm[ct1][ct2] = cs;
        mm[ct2][ct1] = cs;
    }
    cout << dj(c1, c2);
    return 0;
}
