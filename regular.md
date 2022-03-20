## head
```c++
#include <iostream>
#include <cstdlib>
using namespace std;
```
```c++
#define NK 1001
#define ll long long
```

## input

```c++
int a, b;
scanf("%d %d", &a, &b);
```
```c++
int ak;
cin >> ak;
cin >> n >> m >> c1 >> c2;
```

## output

```c++
cout << a;
```
```c++
cout << endl;
```
```c++
printf(" %d %.1f", i, cp[i]);
printf("%d: %s\n", querys[i].first, querys[i].second.c_str());
```

## type define

### normal

```c++
float cp[NK], ct = 0;
```

### struct

```c++
struct Node {
    int hands;
    bool visited = false;
    vector<pair<int, int>> nbs;
    Node* next = NULL;
} nodes[500];

c->hands = ps.size();
```

### array

```c++
node.children = (int*)malloc(k * sizeof(int));
memset(s, 0, sizeof(char) * 101);
```

```c++
int **mat; // 二维数组
```

### lambda
```c++
auto comp = [](Record a, Record b) -> bool {
    return a.in.compare(b.in) < 0;
};
```
```c++
sort(_calls, _calls + n, [](record a, record b) -> bool { return a.raw.compare(b.raw)<0; });
```

## string
```c++
cs.length()
```

```c++
int c = 0;
string cs = to_string(c);
```
```c++
#include <cstring>
strcpy(c1, num.data()), strcpy(c2, s2.data());
```
```c++
s1.compare(s3)
```
```c++
#include <cstring>
char name[9];
strcmp(name, n.name) < 0;
```
```c++
#include <sstream>
snprintf(nsc, sizeof(nsc), "%04d", stoi(ns));//格式化输出到字符串
```
```
int a = stoi("0");
```


## collection

```c++
for_each((*it).second.begin(), (*it).second.end(),[](string name) { printf("%s\n", name.c_str()); });
```

### vector
```c++
#include <vector>

vector<pair<int, int>> nbs;

nbs.push_back({_c1, path});

result.insert(result.begin(), num % base);

```

### queue
```c++
#include <queue>
queue<int> q;
q.push(dict["01"]);
q.pop();
q.front();
!q.empty()
```
### map
```c++
#include <map>
map<int, double> ps;
ps.count(ca);
for (auto i = ps.begin(); i != ps.end(); i++) {
    c->n[k] = i->first;
    c->a[k] = i->second;
    k--;
}
```
### set
```c++
set<int> first, second;
deep(1, first);
deepest = 0;
deep(*first.begin(), second);
first.insert(second.begin(), second.end());
```
```c++
set_intersection(ss[a].begin(), ss[a].end(), ss[b].begin(), ss[b].end(),
                    inserter(inter, inter.begin()));
set_union(ss[a].begin(), ss[a].end(), ss[b].begin(), ss[b].end(),
inserter(inter, inter.begin()));
```

### stack
```c++
#include <stack>
stack<int> dat;
dat.push(0);
dat.top();
dat.pop();
```
## sort
```c++
#include <algorithm>

auto comp = [](Record a, Record b) -> bool {
    return a.in.compare(b.in) < 0;
};
Record *first = min_element(records, records + n, comp);
Record *last = max_element(records, records + n, comp);
```

```c++
#include <algorithm>
sort(exist.begin(), exist.end(),
         [](Node a, Node b) -> bool { return a.key < b.key; });
```

## exception
```c++
try {
    if (to_dec(s_num, i) == target) {
        s_redix = i;
        break;
    }
    throw 0;
} catch (int) {

}
```

## package

```c++
#include <cmath>
sqrt(num);
pow(10, ws);
```

## memory
```c++
#include <string.h>

memset(choose, 0, sizeof(int) * 3);
```
```c++
#include <cstring>
strcpy(c1, num.data()), strcpy(c2, s2.data());
```

## template
```c++
bool is_prime(int num) {
    if (num == 1) return 0;
    if (num == 2 || num == 3) return 1;
    if (num % 6 != 1 && num % 6 != 5) return 0;
    for (int i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    return 1;
}
```

```c++
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
```

```c++
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
```


