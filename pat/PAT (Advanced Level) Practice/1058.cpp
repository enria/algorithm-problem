#include <iostream>

using namespace std;

struct Hogwarts {
    int g, s, k;
};

void add(Hogwarts *a, Hogwarts *b, Hogwarts *result) {//TODO 返回结构体
    int jw = 0;
    jw = (a->k + b->k) / 29;
    result->k = (a->k + b->k) % 29;
    result->s = (jw + a->s + b->s) % 17;
    jw = (jw + a->s + b->s) / 17;
    result->g = (jw + a->g + b->g);
}

int main() {
    Hogwarts a, b, r;
    scanf("%d.%d.%d", &a.g, &a.s, &a.k);//&a.g
    scanf("%d.%d.%d", &b.g, &b.s, &b.k);
    add(&a, &b, &r);
    printf("%d.%d.%d\n", r.g, r.s, r.k);
    return 0;
}