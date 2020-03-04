#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int np, ng;
    cin >> np >> ng;
    int ws[np], rank[np];
    for (int i = 0; i < np; i++) {
        scanf("%d", ws + i);
    }
    vector<int> player;//只记序号
    for (int i = 0, _order; i < np; i++) {
        scanf("%d", &_order);
        player.push_back(_order);
    }
    while (player.size() > 1) {
        vector<int> winner, loser;
        for (int i = 0; i < player.size(); i = i + ng) {
            winner.push_back(*max_element(
                player.begin() + i,
                i + ng < player.size() ? player.begin() + i + ng : player.end(),//begin()+index来修改起始
                [&ws](int a, int b) -> bool { return ws[a] < ws[b]; }));//lambda传环境变量
        }
        for (int i = 0, cur = 0; i < player.size(); i++) {
            if (cur == winner.size() || winner[cur] != player[i]) {
                rank[player[i]] = winner.size() + 1;//有n个人晋级，输的人都是第n名
            } else {
                cur++;
            }
        }
        player = winner;//改变引用
    }
    rank[player[0]] = 1;
    for (int i = 0; i < np; i++) {
        printf(i == 0 ? "%d" : " %d", rank[i]);
    }
    printf("\n");
    return 0;
}