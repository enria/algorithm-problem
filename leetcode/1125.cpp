#include <iostream>
#include <queue>

using namespace std;

struct Comp {
    bool operator()(double a, double b) { return a > b; }
};

int main() {
    priority_queue<double, vector<double>, Comp> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double len;
        scanf("%lf", &len);
        q.push(len);
    }
    while (q.size() >= 2) {
        double len1 = q.top();
        q.pop();
        double len2 = q.top();
        q.pop();
        q.push(len1 / 2 + len2 / 2);
    }
    printf("%d\n", (int)q.top());
    return 0;
}