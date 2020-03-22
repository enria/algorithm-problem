#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>

using namespace std;
struct Person {
    char name[9];
    int height;
    bool operator<(Person p) {
        if (height == p.height) {
            return strcmp(name, p.name) < 0;
        }
        return height > p.height;
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    Person ps[N];
    for (int i = 0; i < N; i++) {
        scanf("%s %d", ps[i].name, &ps[i].height);
    }
    sort(ps, ps + N);
    int idx = 0;
    for (int i = 0; i < K; i++) {
        deque<Person> row;
        int rn = N / K;
        if (i == 0) {
            rn += N - rn * K;
        }
        for (int j = 0; j < rn; j++) {
            if (j % 2) {
                row.push_front(ps[idx++]);
            } else {
                row.push_back(ps[idx++]);
            }
        }
        for (int j = 0; j < rn; j++) {
            printf("%s", row[j].name);
            printf(j == rn - 1 ? "\n" : " ");
        }
    }
    return 0;
}