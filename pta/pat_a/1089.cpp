#include <iostream>
#include <vector>
using namespace std;

int target[100], n;

bool comp(int* num) {
    for (int i = 0; i < n; i++) {
        if (num[i] != target[i]) {
            return false;
        }
    }
    return true;
}

// TODO 传入数组是值还是引用？
// 答：传引用！！！
int* insertSort(int* seq) {
    int num[n];
    for (int i = 0; i < n; i++) {
        num[i] = seq[i];
    }

    bool flag = false;
    for (int i = 1, to, tmp; i < n; i++) {
        to = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (num[j] <= num[i]) {
                to = j + 1;
                break;
            }
        }
        tmp = num[i];
        for (int j = i - 1; j >= to; j--) {
            num[j + 1] = num[j];
        }
        num[to] = tmp;
        if (flag) {
            int* next = (int*)malloc(sizeof(int) * n);
            for (int j = 0; j < n; j++) {
                next[j] = num[j];
            }
            return next;
        }
        if (comp(num)) {
            flag = true;
        }
    }
    return NULL;
}

vector<int> merge(vector<int> a, vector<int> b) {
    int ai = 0, bi = 0;
    vector<int> result;
    while (ai < a.size() || bi < b.size()) {
        if (ai >= a.size()) {
            result.push_back(b[bi++]);
        } else if (bi >= b.size()) {
            result.push_back(a[ai++]);
        } else {
            if (a[ai] < b[bi]) {
                result.push_back(a[ai++]);
            } else {
                result.push_back(b[bi++]);
            }
        }
    }
    return result;
}

int* mergeSort(int* num) {
    vector<vector<int>> result(0);
    for (int i = 0; i < n; i++) {
        result.push_back(vector<int>(1, num[i]));
    }
    bool flag = false;
    while (result.size() > 1) {
        vector<vector<int>> temp;
        for (int i = 0; i < result.size(); i += 2) {
            if (i == result.size() - 1) {
                temp.push_back(result[i]);
            } else {
                temp.push_back(merge(result[i], result[i + 1]));
            }
        }
        for (int i = 0, index = 0; i < temp.size(); i++) {
            for (int j = 0; j < temp[i].size(); j++) {
                num[index++] = temp[i][j];
            }
        }
        if (flag) {
            int* next = (int*)malloc(sizeof(int) * n);
            for (int j = 0; j < n; j++) {
                next[j] = num[j];
            }
            return next;
        }
        if (comp(num)) {
            flag = true;
        }
        result = temp;
    }
    return NULL;
}

int main() {
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", target + i);
    }
    int* result = insertSort(num);
    string sortName = "Insertion Sort";
    if (!result) {
        result = mergeSort(num);
        sortName = "Merge Sort";
    }
    cout << sortName << endl;
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        printf(i == n - 1 ? "\n" : " ");
    }
    return 0;
}