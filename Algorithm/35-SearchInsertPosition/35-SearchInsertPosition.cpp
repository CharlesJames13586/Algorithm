#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 0) {
            //��������
            int i = 0;
            while (i < len && nums[i] < target) {
                i++;
            }
            return i;
        }
        else {
            //���淨
            int low = 0, high = len - 1;
            int p = (low + high) / 2;
            while (low < high) {
                if (nums[p] == target) {
                    break;
                }
                else if(nums[p] < target){
                    low = p + 1;
                    p = (low + high) / 2;
                }
                else if (nums[p] > target) {
                    high = p - 1;
                    p = (low + high) / 2;
                }
            }
            while (p<len && nums[p]<target) {
                p++;
            }
            return p;
        }
        
    }
};

int main() {
    vector<int>nums;
    int len = 0;
    int target = 0;
    cout << "���������鳤��" << endl;
    cin >> len;
    int temp = 0;
    for (int i = 0; i < len; i++) {
        cout << "�������" << i + 1 << "��ֵ��";
        cin >> temp;
        cout << endl;
        nums.push_back(temp);
    }
    cout << "������Ҫ�ҵ�ֵ" << endl;
    cin >> target;
    Solution solution;
    cout << solution.searchInsert(nums, target)<<endl;
    return 0;
}