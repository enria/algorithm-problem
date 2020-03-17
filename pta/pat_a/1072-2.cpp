#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct Node {
    int v, dis;
} node;
struct compare {
    bool operator()(Node n1, Node n2) { return n1.dis > n2.dis; }
};
struct Result {
    string solution;
    double mindistance, averagedistance;
    bool operator<(Result r) {
        if (mindistance != r.mindistance)
            return mindistance > r.mindistance;  //最大的最近距离，注意理解题意
        else if (averagedistance != r.averagedistance)
            return averagedistance < r.averagedistance;
        else
            return solution < r.solution;
    }
} result;
int N, M, K, Ds;
const int maxn = 1020;  //这里注意maxn必须是1011以上
const int INF = 1000000000;
map<string, int> gas2num;
map<int, string> num2gas;
vector<Node> Adj[maxn];
bool vis[maxn];
int d[maxn];
vector<Result> solutions;
void Dijkstra(int s) {
    fill(vis, vis + maxn, false);
    fill(d, d + maxn, INF);
    d[s] = 0;
    priority_queue<Node, vector<Node>, compare> Q;
    node.v = s;
    node.dis = 0;
    Q.push(node);
    int u;
    for (int i = 1; i <= N + M; i++) {
        if (!Q.empty()) {
            u = Q.top().v;
            vis[u] = true;
            Q.pop();
        }
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;
            if (!vis[v] && d[u] + dis < d[v]) {
                d[v] = d[u] + dis;
                node.v = v;
                node.dis = d[v];
                Q.push(node);
            }
        }
    }
    double sum = 0.0;
    result.mindistance = INF;
    for (int i = 1; i <= N; i++) {
        if (d[i] > Ds)
            return;
        else
            sum += d[i];
        if (result.mindistance > d[i]) {
            result.mindistance = d[i];
        }
    }
    result.solution = num2gas[s];
    result.averagedistance = sum / N;
    solutions.push_back(result);
}
int main() {
    scanf("%d%d%d%d", &N, &M, &K, &Ds);
    string s1, s2;
    int distance;
    int n = N;
    for (int i = 0; i < K; i++) {
        cin >> s1 >> s2 >> distance;
        int v1, v2;
        if (s1[0] != 'G') {
            // v1 = s1[0] - '0';这个地方注意若输入的是10以上的数就不行
            v1 = stoi(s1);
        } else {
            if (gas2num.find(s1) == gas2num.end()) {
                v1 = gas2num[s1] = ++n;
                num2gas[n] = s1;
            } else
                v1 = gas2num[s1];
        }
        if (s2[0] != 'G') {
            // v2 = s2[0] - '0';
            v2 = stoi(s2);
        } else {
            if (gas2num.find(s2) == gas2num.end()) {
                v2 = gas2num[s2] = ++n;
                num2gas[n] = s2;
            } else
                v2 = gas2num[s2];
        }
        node.v = v2;
        node.dis = distance;
        Adj[v1].push_back(node);
        node.v = v1;
        Adj[v2].push_back(node);
    }
    for (int i = N + 1; i <= N + M; i++) {
        Dijkstra(i);
    }
    if (solutions.size()) {
        sort(solutions.begin(), solutions.end());
        cout << solutions[0].solution << endl;
        printf("%.1f %.1f\n", solutions[0].mindistance,
               solutions[0].averagedistance);
    } else
        printf("No Solution\n");
    return 0;
}