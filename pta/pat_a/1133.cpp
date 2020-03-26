#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int k;

struct Node {
    int add, order, data, next;
    Node() {}
    Node(int a, int b, int c) : add(a), data(b), next(c) {}
} nums[100000];

bool comp(Node a, Node b) {
    if (a.data < 0 && b.data < 0) return a.order < b.order;
    if (a.data >= 0 && a.data <= k && b.data >= 0 && b.data <= k)
        return a.order < b.order;
    if (a.data > k && b.data > k) return a.order < b.order;
    return a.data < b.data;
}

int main() {
    int head, n;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i++) {
        int add, data, next;
        scanf("%d %d %d", &add, &data, &next);
        nums[add] = {add, data, next};
    }
    vector<Node> link;
    for (int i = 0; head != -1; i++) {
        nums[head].order = i;
        link.push_back(nums[head]);
        head = nums[head].next;
    }
    sort(link.begin(), link.end(), comp);
    for (int i = 0; i < link.size(); i++) {
        printf("%05d %d ", link[i].add, link[i].data);
        if (i == link.size() - 1) {
            printf("-1\n");
        } else {
            printf("%05d\n", link[i + 1].add);
        }
    }

    return 0;
}