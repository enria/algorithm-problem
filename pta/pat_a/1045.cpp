#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<pair<int, int>> seq;          //第一个颜色，第二个是数量
map<int, int> index;                 //第一个是颜色，第二个是序号
map<int, int> cache;                 //从第i个开始的
int comput(int start, int maxidx) {  //选择的不能大于maxidx
    if (start < 0) {
        return 0;
    }
    if (cache[start]) {
        return cache[start];
    }
    int choose_cur = seq[start].second, maxo = -1,
        curidx = index[seq[start].first];
    bool flag = false;
    for (int i = start - 1; i >= 0; i--) {
        if (!flag && index[seq[i].first] < curidx) {
            choose_cur += comput(i, curidx);
            flag = true;
        }
        if (index[seq[i].first] >= curidx && index[seq[i].first] < maxidx) {
            if (maxo == -1) {
                maxo = comput(i, curidx);
            } else {
                int temp = comput(i, curidx);
                if (temp > maxo) maxo = temp;
            }
        }
    }
    // printf("start:%d cur:%d maxo:%d\n", start, choose_cur, maxo);
    cache[start] = max(choose_cur, maxo);
    return cache[start];
}

int main() {
    int n, m, l;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int c;
        scanf("%d", &c);
        index[c] = i;
    }
    cin >> l;
    vector<int> cs;
    for (int i = 0; i < l; i++) {
        int c;
        scanf("%d", &c);
        if (index[c]) {
            cs.push_back(c);
        }
    }
    seq.push_back(pair<int, int>{cs[0], 1});
    int cur = 0;
    for (int i = 1; i < cs.size(); i++) {
        if (cs[i] == seq[cur].first) {
            seq[cur].second++;
        } else {
            seq.push_back(pair<int, int>{cs[i], 1});
            cur++;
        }
    }
    cout << comput(seq.size() - 1, index.size() + 1) << endl;
    return 0;
}