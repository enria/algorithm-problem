#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

int **mat;

void print(int **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int bfs(int **mat, int n, int a) {
    int gs = 0;
    queue<int> q;
    int visited[n];
    // BUG 新建数组，没有设置数据里面的内容
    memset(visited, 0, sizeof(int) * n);
    visited[a] = 1;
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }
        q.push(i);
        while (q.size()) {
            int f = q.front();
            q.pop();
            visited[f] = 1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && mat[f][j]) {
                    q.push(j);
                }
            }
        }
        gs++;
    }
    return gs;
}

void dfs(int **mat, int n, int a, int *visited) {
    visited[a] = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && mat[a][i]) {
            dfs(mat, n, i, visited);
        }
    }
}

int dfss(int **mat, int n, int a) {
    int visited[n];
    memset(visited, 0, sizeof(int) * n);
    int gs = 0;
    visited[a] = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(mat, n, i, visited);
            gs++;
        }
    }
    return gs;
}


int fn(int *root, int n, int a) {
    if (root[a] == a) {
        return a;
    } else {
        return fn(root, n, root[a]);
    }
}
//TODO 并查集优化？
int uf(int relation[][2], int m, int n, int a) {
    int root[n];
    for (int i = 0; i < n; i++) {
        root[i] = i;
    }
    for (int i = 0; i < m; i++) {
        if(relation[i][0]==a||relation[i][1]==a){
            continue;
        }
        int fa = fn(root, n, relation[i][0]), fb = fn(root, n, relation[i][1]);
        if (fa != fb) {
            root[fb] = fa;
        }
    }
    int gs=0;
    for (int i = 0; i < n; i++)
    {
        if(root[i]==i&&i!=a){
            gs++;
        }
    }
    return gs; 
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    mat = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n + 1; i++) {
        mat[i] = (int *)malloc(sizeof(int) * n);
    }
    int relation[m][2];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        mat[a][b] = 1;
        mat[b][a] = 1;
        relation[i][0]=a;
        relation[i][1]=b;
    }
    int ka[k];
    for (int i = 0; i < k; i++) {
        cin >> ka[i];
        ka[i] = ka[i] - 1;
    }
    for (int i = 0; i < k; i++) {
        cout << uf(relation,m,n,ka[i]) - 1 << endl;
    }
    return 0;
}