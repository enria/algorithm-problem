#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// TODO dfs
// TODO dp

int N, K, P;

vector<vector<int>> sols;
void dfs(int num, int index, int nog, vector<int> &result) {
    if (num > index * (pow(nog, P)) || num < index) {
        return;  //这个剪枝牛逼啊，从最大和最小两个方面去考虑它
    }
    if (num <= 0 || index == 0) {
        if (num == 0 && index == 0) {
            sols.push_back(result);
        }
        return;
    }
    for (int i = 1; i <= min((int)pow(num, 1.0 / P), nog); i++) {
        result.push_back(i);
        dfs(num - pow(i, P), index - 1, i, result);
        result.pop_back();
    }
}

bool comp(vector<int> a, vector<int> b) {
    int sa = 0, sb = 0;
    for (int i = 0; i < K; i++) {
        sa += a[i], sb += b[i];
    }
    if (sa == sb) {
        for (int i = 0; i < K; i++) {
            if (a[i] != b[i]) return a[i] > b[i];
        }
    }
    return sa > sb;
}

int main() {
    cin >> N >> K >> P;
    vector<int> result;
    dfs(N, K, N, result);
    sort(sols.begin(), sols.end(), comp);
    if (sols.size()) {
        for (int i = 0; i < 1; i++) {
            printf("%d = ", N);
            for (int j = 0; j < sols[i].size(); j++) {
                if (j != 0) printf("+ ");
                printf("%d^%d", sols[i][j], P);
                printf(j == sols[i].size() - 1 ? "\n" : " ");
            }
        }
    } else {
        printf("Impossible\n");
    }
    return 0;
}