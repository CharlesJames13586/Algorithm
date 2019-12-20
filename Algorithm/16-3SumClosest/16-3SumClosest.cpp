#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        if (nums.size() <= 2) {
            for (int i = 0; i < nums.size(); i++) {
                result = result + nums[i];
            }
            return result;
        }
        
        sort(nums.begin(), nums.end());      //sort�Ը����������������������
        result = nums[0] + nums[1] + nums[2];
        int left = 0, right = 0, temp=0;
        for (int i = 0; i < nums.size() - 2; i++) {
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                temp = nums[i] + nums[left] + nums[right];
                if (abs(temp-target) == 0) {
                    //�����ȣ�����
                    return temp;
                }
                else if (abs(temp - target) < abs(result - target)) {
                    //����и����ģ�����
                    result = temp;
                }
                else if (abs(temp - target) > abs(result - target)) {
                    //������Ǹ����ģ�������һ��
                }

                //����left,rightָ��
                if (temp < target) {
                    left++;
                }
                else if (temp > target) {
                    right--;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums;
    cout << "������nums�����Ĵ�С��";
    int n = 0, temp = 0;     //n��¼nums�Ĵ�С��temp����ʱ��ʱ��¼numsԪ�ص�ֵ
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }

    cout << "������target��ֵ��";
    int target = 0;
    cin >> target;
    cout << endl;

    Solution solution;
    int result = solution.threeSumClosest(nums, target);

    cout << result;

    return 0;
}