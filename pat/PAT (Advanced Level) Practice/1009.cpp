#include <iostream>
#include <map>

using namespace std;

struct poly {
    int k;
    int *n;
    double *a;
};

void init(poly *a) {
    cin >> a->k;
    a->n = (int *)malloc(sizeof(int) * a->k);
    a->a = (double *)malloc(sizeof(double) * a->k);
    for (int i = 0; i < a->k; i++) {
        cin >> a->n[i] >> a->a[i];
    }
}

void multiply(poly a, poly b, poly *c) {
    map<int, double> ps;
    for (int i = 0; i < b.k; i++) {
        for (int j = 0; j < a.k; j++) {
            int ca = b.n[i] + a.n[j];
            if (ps.count(ca)) {
                ps[ca] = ps[ca] + b.a[i] * a.a[j];
            } else {
                ps[ca] = b.a[i] * a.a[j];
            }
        }
    }
    c->k = ps.size();
    c->n = (int *)malloc(sizeof(int) * c->k);
    c->a = (double *)malloc(sizeof(double) * c->k);
    int k = c->k - 1;
    for (auto i = ps.begin(); i != ps.end(); i++) {
        c->n[k] = i->first;
        c->a[k] = i->second;
        k--;
    }
}

void disp(poly a) {
    cout << a.k;
    for (int i = 0; i < a.k; i++) {
        printf(" %d %.1f", a.n[i], a.a[i]);
    }
    cout << endl;
}

int main() {
    poly a, b, c;
    init(&a), init(&b);
    multiply(a, b, &c);
    disp(c);
    return 0;
}