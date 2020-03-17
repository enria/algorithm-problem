#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

bool comp(char num1[], char num2[]) {
    int len1 = strlen(num1), len2 = strlen(num2);
    for (int i = 0; i < len1 && i < len2; i++) {
        if (num1[i] != num2[i]) {
            return num1[i] < num2[i];
        }
    }
    bool result = false;
    if (len1 > len2) {
        result = comp(num1 + len2, num2);
    } else if (len1 < len2) {
        result = comp(num1, num2 + len1);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<char *> nums;
    for (int i = 0; i < n; i++) {
        char *num = (char *)malloc(sizeof(char) * 9);
        scanf("%s", num);
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end(), comp);
    bool flag = true;  //首位
    for (int i = 0; i < nums.size(); i++) {
        if (flag) {
            int num = stoi(nums[i]);
            if (num || i == nums.size() - 1) {
                printf("%d", num);
                flag = false;
            }
        } else {
            printf("%s", nums[i]);
        }
        if (i == nums.size() - 1) printf("\n");
    }

    return 0;
}