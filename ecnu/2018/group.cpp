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
    vector<int> dir(superior.size());     //ֱ���¼�������
    vector<int> report(superior.size());  //�Ѿ������ֱ���¼�����
    vector<int> num(superior.size());     //�¼�����
    for (int i = 0; i < superior.size(); i++) {  //����ֱ���¼�����
        if (superior[i] != 0) {
            dir[superior[i] - 1] += 1;
        }
    }
    bool finish = false;
    while (!finish) {
        for (int i = 0; i < superior.size(); i++) {
            if (dir[i] != -1) {
                if (dir[i] == report[i]) {  //����ֱ���¼����Ѿ��������
                    if (superior[i] == 0) {  //�ų���ֱ���¼���������˴������
                        finish = true;
                        num[i] += 1;
                        break;
                    }
                    num[i] += 1;                     //�����Լ�
                    num[superior[i] - 1] += num[i];  //����
                    report[superior[i] - 1] += 1;
                    dir[i] = -1;  //�Ѿ��������
                }
            }
        }
    }
    return num;
}