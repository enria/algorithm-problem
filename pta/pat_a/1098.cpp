#include <iostream>

using namespace std;

int target[101], n;

bool comp(int *num) {
    for (int i = 0; i < n; i++) {
        if (num[i] != target[i]) {
            return false;
        }
    }
    return true;
}

int *insertSort(int *origin) {
    int num[n];
    for (int i = 0; i < n; i++) {
        num[i] = origin[i];
    }
    bool flag = false;
    for (int i = 1, pos, cur; i < n; i++) {
        pos = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (num[j] <= num[i]) {
                pos = j + 1;
                break;
            }
        }
        cur = num[i];
        for (int j = i - 1; j >= pos; j--) {
            num[j + 1] = num[j];
        }
        num[pos] = cur;

        if (flag) {
            int *result = (int *)malloc(sizeof(int) * n);
            for (int j = 0; j < n; j++) {
                result[j] = num[j];
            }
            return result;
        }
        if (comp(num)) {
            flag = true;
        }
    }
    return NULL;
}

void exchange(int *num, int a, int b) {
    int temp = num[a];
    num[a] = num[b];
    num[b] = temp;
}

void adjust(int *num, int root, int end) {
    int rootval = num[root];
    int cur = root, to, temp;
    while (1) {
        to = cur, temp = rootval;  //需要换到index, 当前最大值
        for (int i = cur * 2 + 1; i < end && i <= cur * 2 + 2; i++) {
            if (num[i] > temp) {
                to = i;
                temp = num[i];
            }
        }
        if (to == cur) {
            break;  //没变，调整结束
        } else {
            num[cur] = num[to];
            cur = to;  //继续下探
        }
    }
    num[cur] = rootval;
}

int *heapSort(int *origin) {
    int num[n];
    for (int i = 0; i < n; i++) {
        num[i] = origin[i];
    }
    // build head
    for (int i = n / 2 - 1; i >= 0; i--) {
        adjust(num, i, n);
    }
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {  //调整n-1次，剩下的最后一个是最小的
        exchange(num, 0, n - 1 - i);
        // adjust heap
        adjust(num, 0, n - 1 - i);
        if (flag) {
            int *result = (int *)malloc(sizeof(int) * n);
            for (int j = 0; j < n; j++) {
                result[j] = num[j];
            }
            return result;
        }
        if (comp(num)) {
            flag = true;
        }
    }
    return NULL;
}

int main() {
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", num + i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", target + i);
    }
    int *result = insertSort(num);
    string sortm = "Insertion Sort";
    if (!result) {
        result = heapSort(num);
        sortm = "Heap Sort";
    }

    cout << sortm << endl;
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        printf(i == n - 1 ? "\n" : " ");
    }

    return 0;
}