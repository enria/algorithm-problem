#include <iostream>
#include <vector>

using namespace std;
vector<int> groupPolulation(vector<int> superior);
int main(void) {
    vector<int> nums = {0, 1, 2, 1, 2, 2};
    nums = groupPolulation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}

vector<int> groupPolulation(vector<int> superior) {
    vector<int> dir(superior.size());     //直接下级的人数
    vector<int> report(superior.size());  //已经报告的直接下级人数
    vector<int> num(superior.size());     //下级人数
    for (int i = 0; i < superior.size(); i++) {  //计算直接下级人数
        if (superior[i] != 0) {
            dir[superior[i] - 1] += 1;
        }
    }
    bool finish = false;
    while (!finish) {
        for (int i = 0; i < superior.size(); i++) {
            if (dir[i] != -1) {
                if (dir[i] == report[i]) {  //所有直接下级都已经报告过了
                    if (superior[i] == 0) {  //团长的直接下级都报告过了代表结束
                        finish = true;
                        num[i] += 1;
                        break;
                    }
                    num[i] += 1;                     //加上自己
                    num[superior[i] - 1] += num[i];  //报告
                    report[superior[i] - 1] += 1;
                    dir[i] = -1;  //已经报告过了
                }
            }
        }
    }
    return num;
}