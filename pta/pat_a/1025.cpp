#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// [check] TODO 先试试将所有的都放在一起
// TODO 再试试归并排序
// TODO 再试试败者树


struct testee {
    string number;//不能用long存储，序号可能以0开始
    int local;
    int score, local_rank, total_rank;
};

bool comp(testee a, testee b) {
    if (a.score == b.score) {
        return a.number < b.number;
    }
    return a.score > b.score;
}

vector<testee> testees;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        testee _ts[k];
        for (int j = 0; j < k; j++) {
            cin >> _ts[j].number >> _ts[j].score;
            _ts[j].local = i;
        }
        sort(_ts, _ts + k, comp);
        int rank = 1;
        _ts[0].local_rank = 1;
        testees.push_back(_ts[0]);
        for (int j = 1; j < k; j++) {
            if (_ts[j - 1].score == _ts[j].score) {
                _ts[j].local_rank = rank;
            } else {
                _ts[j].local_rank = (rank = j + 1);
            }
            testees.push_back(_ts[j]);
        }
    }

    sort(testees.begin(), testees.end(), comp);

    int rank = 1;
    testees[0].local_rank = 1;
    cout << testees.size() << endl;
    printf("%s %d %d %d\n", testees[0].number.c_str(), rank, testees[0].local,
           testees[0].local_rank);
    for (int j = 1; j < testees.size(); j++) {
        if (testees[j - 1].score != testees[j].score) {
            rank = j + 1;
        }
        printf("%s %d %d %d\n", testees[j].number.c_str(), rank,
               testees[j].local, testees[j].local_rank);
    }
    return 0;
}