#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
int times[50001];

struct LinkNode {
    int id, cnt;
    LinkNode *pre, *next;
    bool operator<(LinkNode b) {
        if (cnt == b.cnt) {
            return id < b.id;
        }
        return cnt > b.cnt;
    }
};

int main() {
    map<int, LinkNode *> cnt;
    map<int, set<int>> ids;
    int n, k;
    cin >> n >> k;
    LinkNode *head = (LinkNode *)malloc(sizeof(LinkNode));
    LinkNode *tail = head;
    for (int i = 0; i < n; i++) {
        vector<int> rs;
        int j = 0;
        LinkNode *cur = head->next;
        while (cur && j < k) {
            rs.push_back(cur->id);
            cur = cur->next;
            j++;
        }
        int id;
        scanf("%d", &id);
        if (rs.size()) {
            printf("%d:", id);
            for (j = 0; j < rs.size(); j++) {
                printf(" %d", rs[j]);
            }
            printf("\n");
        }
        if (cnt[id]) {
            cnt[id]->cnt++;
        } else {
            cnt[id] = (LinkNode *)malloc(sizeof(LinkNode));
            cnt[id]->id = id, cnt[id]->cnt = 1;
            tail->next = cnt[id];
            cnt[id]->pre = tail;
            tail = cnt[id];
            tail->next = NULL;
        }
        while (cnt[id]->pre != head) {
            if (*(cnt[id]) < *(cnt[id]->pre)) {
                LinkNode *pre = cnt[id]->pre, *next = cnt[id]->next;
                cnt[id]->pre = pre->pre;
                pre->pre->next = cnt[id];
                cnt[id]->next = pre;
                pre->pre = cnt[id];
                if (next) {
                    pre->next = next;
                    next->pre = pre;
                } else {
                    pre->next = NULL;
                    tail = pre;
                }
            } else {
                break;
            }
        }
    }
    return 0;
}