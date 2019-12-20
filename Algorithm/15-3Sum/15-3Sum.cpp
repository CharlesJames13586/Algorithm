#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;//�������ս��������
        vector<int> temp;//��ʱ�������Ҫ��ļ���
        sort(nums.begin(), nums.end());      //sort�Ը����������������������
        //������������鳤�Ȳ�����2�����ý��д���û�з���Ҫ��Ĵ�
        if (nums.size() <= 2) {        
            return result;
        }
        //��������ĳ��ȴ��ڵ���3
        int left = 0, right = 0, target = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                //���nums[i]����ǰ�����ڵ�nums[i-1]��ȣ�������������ó��ظ��ļ���
                continue;
            }
            left = i + 1;
            right = nums.size() - 1;
            target = 0;
            while (left < right) {
                //���±�Ϊi,left,right��Ԫ�ؽ��мӺͣ���0�����ж�
                target = nums[i] + nums[left] + nums[right];
                if (target == 0) {
                    //�������0�������Ҫ�󣬼���result
                    temp = { nums[i],nums[left],nums[right] };
                    result.push_back(temp);
                    //��nums[i]����Ҫ��Ŀ��ܲ�ֹһ�������Ի���Ҫ
                    //����Ҫ�޳��ظ���
                    while (left < right && nums[left + 1] == nums[i]) {
                        left++;
                    }
                    while (right > left && nums[right - 1] == nums[right]) {
                        right--;
                    }
                    //�����Ƚ�
                    left++;
                    right--;
                }
                else if (target < 0) {
                    //���С��0������left,����target����
                    left++;
                }
                else if (target > 0) {
                    //�������0������right������target���С
                    right--;
                }
            }
        }
        return result;
    }
};

//�������Ե�������
int main() {
    vector<int> nums; 
    vector<vector<int>> result;
    int n = 0;        //��¼nums����Ԫ�صĸ���
    int temp = 0;     //������ʱ��¼����numsԪ�ص�ֵ
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);      //push_back()��vectorβ���һ��Ԫ��
    }
    Solution solution;
    result = solution.threeSum(nums);
    //������
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << ' ' << result[i][1]<<' '<< result[i][2]  <<endl;
    }

    return 0;
}