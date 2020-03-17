#include <cstring>
#include <iostream>
#include <stack>

using namespace std;
int nums[100001];

const char invalids[] = "Invalid\n";

int main() {
    int n;
    cin >> n;
    int pre = 0, post = 0, cur = -1;
    stack<int> s;
    char op[20];
    for (int i = 0, num; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "Push") == 0 || strcmp(op, "Pop") == 0) {
            if (strcmp(op, "Push") == 0) {
                scanf("%d", &num);
                s.push(num), nums[num]++;
                if (cur == -1) {
                    cur = num;
                } else {
                    if (num < cur) pre++;
                    if (num > cur) post++;
                }
            } else if (strcmp(op, "Pop") == 0) {
                if (cur == -1) {
                    printf(invalids);
                    continue;
                } else {
                    num = s.top();
                    printf("%d\n", num);
                    s.pop(), nums[num]--;
                    if (num < cur) pre--;
                    if (num > cur) post--;
                    if (!s.size()) cur = -1;
                }
            }
            //调整中值
            if (pre >= post + nums[cur]) {
                for (int j = cur - 1; j > 0; j--) {
                    if (nums[j] > 0) {
                        post += nums[cur];
                        cur = j;
                        pre -= nums[j];
                        break;
                    }
                }
            } else if (post > pre + nums[cur]) {
                for (int j = cur + 1;; j++) {
                    if (nums[j] > 0) {
                        pre += nums[cur];
                        cur = j;
                        post -= nums[j];
                        break;
                    }
                }
            }
        } else {
            if (cur == -1) {
                printf(invalids);
            } else {
                printf("%d\n", cur);
            }
        }
    }
    return 0;
}