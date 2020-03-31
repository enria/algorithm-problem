#include <iostream>

using namespace std;

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 6 != 1 && num % 6 != 5) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}
int min_prime(int num) {
    while (!is_prime(num)) {
        num++;
    }
    return num;
}

int *nums, msize, n, m;

bool insert(int num) {
    int hash = num % msize;
    for (int i = 0; i <= msize; i++) {  // 1. 插入的时候，是等于msize
        int pos = (i * i + hash) % msize;  // 2. 搜索的时候，要取模
        if (nums[pos] == 0) {
            nums[pos] = num;
            return true;
        }
    }
    return false;
}

int search(int num) {
    int hash = num % msize;
    int st = 0;
    for (int i = 0; i <= msize; i++) {
        st++;
        int pos = (i * i + hash) % msize;
        if (nums[pos] == num || nums[pos] == 0) {  // 3. 如果等于0，那就是不存在
            break;
        }
    }
    return st;
}

int main() {
    cin >> msize >> n >> m;
    msize = min_prime(msize);
    nums = (int *)malloc(sizeof(int) * msize);
    for (int i = 0, num; i < n; i++) {
        scanf("%d", &num);
        bool insted = insert(num);
        if (!insted) printf("%d cannot be inserted.\n", num);
    }
    int tst = 0;
    for (int i = 0, num; i < m; i++) {
        scanf("%d", &num);
        int st = search(num);
        tst += st;
    }
    printf("%.1f\n", tst * 1.0 / m);
    return 0;
}