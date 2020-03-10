#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int perfact[6], k;
struct User {
    int id;
    int problems[5];
    int solved, submited, score;  //初始值是0吗？
    bool operator<(User u) {
        if (score == u.score) {
            if (solved == u.solved) {
                return id < u.id;
            }
            return solved > u.solved;
        }
        return score > u.score;
    }
    User() {
        for (int i = 0; i < 5; i++) {
            problems[i] = -2;  //默认没提交
        }
    };
};

//形参会改变量面的值吗？
void comput(User *user) {
    for (int i = 0; i < k; i++) {
        if (user->problems[i] >= 0) {
            user->submited++;
            if (user->problems[i] == perfact[i]) {
                user->solved++;
            }
            user->score += user->problems[i];
        }
    }
}

int main() {
    int n, m;
    cin >> n >> k >> m;
    for (int i = 0; i < k; i++) {
        scanf("%d", perfact + i);
    }

    map<int, User> dat;
    int _id, _p, _score;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &_id, &_p, &_score);
        _p--;
        if (dat[_id].problems[_p] < _score) {
            dat[_id].problems[_p] = _score;
        }
    }
    vector<User> ranklist;  // TODO 试试只传入指针
    for (auto it = dat.begin(); it != dat.end(); it++) {
        it->second.id = it->first;
        comput(&(it->second));
        if (it->second.submited) {
            ranklist.push_back(it->second);
        }
    }
    sort(ranklist.begin(), ranklist.end());
    int rank = 1;
    for (int i = 0; i < ranklist.size(); i++) {
        if (i != 0) {
            if (ranklist[i].score != ranklist[i - 1].score) {
                rank = i + 1;
            }
        }
        printf("%d %05d %d", rank, ranklist[i].id, ranklist[i].score);
        for (int j = 0; j < k; j++) {
            if (ranklist[i].problems[j] >= 0) {
                printf(" %d", ranklist[i].problems[j]);
            } else if (ranklist[i].problems[j] == -1) {  //没通过分数是0
                printf(" 0");
            } else {
                printf(" -");
            }
        }
        printf("\n");
    }
    return 0;
}