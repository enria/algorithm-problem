#include <iostream>
#include <set>

using namespace std;

int friendId(int num) {
    int id = 0;
    while (num) {
        id += num % 10;
        num = num / 10;
    }
    return id;
}

int main() {
    int n, num;
    cin >> n;
    set<int> ids;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        ids.insert(friendId(num));
    }
    printf("%lu\n", ids.size());
    for (auto it = ids.begin(); it != ids.end(); it++) {
        printf(it == ids.begin() ? "%d" : " %d", *it);
    }
    printf("\n");
    return 0;
}