#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-3; i++) {
            if (nums[i] > target && nums[i] >= 0) {
                break;
            }
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size()-2; j++) {
                if (nums[i] + nums[j] > target && nums[i]+nums[j] >= 0) {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
                    else {
                        res.push_back({ nums[i] , nums[j] , nums[left] , nums[right] });
                        while (left < right && nums[left] == nums[left + 1])left++;
                        while (left < right && nums[right] == nums[right - 1])right--;
                        left++; right--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = { 1,0,-1,0,-2,2 };
	Solution qq;
    vector<vector<int>> res = qq.fourSum(nums,0);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            printf("%d ", res[i][j]);
        }
        cout << endl;
    }
    return 0;
}