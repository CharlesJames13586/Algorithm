#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printResult(vector<vector<int>> &result);

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //�ж�nums�Ĵ�С�Ƿ���ڵ���4
        int len = nums.size();
        vector<vector<int>> result;    //������
        if (len < 4) {
            return result;
        }
        //���ȶ�nums��������ʹ��<algorithm>��sort()����
        sort(nums.begin(), nums.end());
        
        int left = 0, right = 0;       //����ָ��
        int temp = 0;        //�����м�Ҫ�����жϵĺ�
        
        //����ѭ����˫ָ��
        for (int i = 0; i < len-3; i++) {
            //��ֹ�ظ�
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            //��ǰ�ĸ����ĺʹ���Ŀ��ֵʱ����ȷ���Ѿ�û�÷��������Ľ⣬ֱ���˳�ѭ��
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            //����һ�����ͺ��������ĺ�С��Ŀ��ֵʱ����ȷ������ѭ��û�÷��������Ľ⣬������һ��ѭ��
            if (nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target) {
                continue;
            }
            for (int j = i + 1; j < len-2; j++) {
                //��j�Ĵ������i�Ĵ���ʽ����
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if (nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target) {
                    continue;
                }
                left = j + 1;
                right = len-1;
                while (left < right) {
                    //��ʼ�ж��Ƿ��target���
                    temp = nums[i] + nums[j] + nums[left] + nums[right];
                    if (temp == target) {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        //����������ʵʱ����������������ύʱ��ע�͵�
                        //cout << nums[i] << ',' << nums[j] << ',' << nums[left] << ',' << nums[right] << endl;
                        //����do-while���������ȥ��
                        //ע���ж�left��right�ĺϷ��ԣ��������������С
                        do {
                            left++;
                        } while (left<len && nums[left] == nums[left - 1]);
                        do {
                            right--;
                        } while (right>j && nums[right] == nums[right + 1]);
                    }
                    else if (temp < target) {
                        left++;
                    }
                    else if (temp > target) {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

//���ڲ��Ե�������
int main() {
    vector<int> nums;
    int n = 0;
    cout << "����������nums�ĸ�����";
    cin >> n;
    cout << endl;
    int num = 0;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }
    cout << "nums��������ϣ�" << endl;
    int target = 0;
    cout << "������target��ֵ��";
    cin >> target;
    cout << endl;
    vector<vector<int>> result;
    Solution solution;
    result = solution.fourSum(nums, target);
    printResult(result);

    return 0;
}

void printResult(vector<vector<int>> &result) {
    cout << "A solution set is:" << endl;
    cout << "[" << endl;
    int len = result.size();
    for (int i = 0; i < len; i++) {
        cout << "[";
        int len_son = result[i].size();
        for (int j = 0; j < len_son; j++) {
            if (j == len_son - 1) {
                cout << result[i][j] << ' ';
            }
            else {
                cout << result[i][j] << ',' << ' ';
            }
        }
        if (i == len - 1) {
            cout << "]" << endl;
        }
        else {
            cout << "]" << ',' << endl;
        }
    }
    cout << "]" << endl;
}