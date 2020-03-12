#include <iostream>
#include <map>
#include <queue>

using namespace std;

// 1是core,0是normal,-1是被遍历过了
int space[60][1286][128], n, m, l;
struct Point {
    int li, mi, ni;
};
int key(int li, int mi, int ni) { return li * 128 * 1286 + mi * 128 + ni; }
map<int, int> index;
int offsets[6][3] = {{-1, 0, 0}, {1, 0, 0},  {0, -1, 0},
                     {0, 1, 0},  {0, 0, -1}, {0, 0, 1}};

// root是0号病人,其实就是深度优先，找出图的连通个数
//深度优先会段错误（栈帧太多），改成广度优先，与树的层次遍历一个道理
void infect(int root, int li, int mi, int ni) {
    queue<Point> q;
    index[root]++, space[li][mi][ni] = -1;
    q.push(Point{li, mi, ni});
    Point cur, x;
    while (q.size()) {
        cur = q.front();
        for (int i = 0; i < 6; i++) {
            int *offset = offsets[i];
            x = Point{cur.li + offset[0], cur.mi + offset[1],
                      cur.ni + offset[2]};
            if (x.li >= l || x.li < 0 || x.mi >= m || x.mi < 0 || x.ni >= n ||
                x.ni < 0 || space[x.li][x.mi][x.ni] == -1 ||
                space[x.li][x.mi][x.ni] == 0) {
                continue;
            }
            //要在这里就加上标记，否则一个节点会入队多次
            index[root]++, space[x.li][x.mi][x.ni] = -1;
            q.push(x);
        }
        q.pop();
    }
    return;
}

int main() {
    int t;
    cin >> m >> n >> l >> t;
    for (int li = 0; li < l; li++) {
        for (int mi = 0; mi < m; mi++) {
            for (int ni = 0; ni < n; ni++) {
                scanf("%d", &space[li][mi][ni]);
            }
        }
    }
    for (int li = 0; li < l; li++) {
        for (int mi = 0; mi < m; mi++) {
            for (int ni = 0; ni < n; ni++) {
                if (space[li][mi][ni] == -1 || space[li][mi][ni] == 0) {
                    continue;
                }
                infect(key(li, mi, ni), li, mi, ni);
            }
        }
    }
    int sum = 0;
    for (auto it = index.begin(); it != index.end(); it++) {
        if (it->second >= t) sum += it->second;
    }
    cout << sum << endl;
    return 0;
}