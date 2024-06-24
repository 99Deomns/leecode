#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return res;
            }
            if (i&&nums[i]==nums[i-1]) {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            int sum = 0;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    res.push_back({ nums[i],nums[left],nums[right] });
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    right--; left++;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = { -2,0,0,2,2 };
	Solution qq;
    vector<vector<int>> res = qq.threeSum(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            printf("%d ", res[i][j]);
        }
        cout << endl;
    }
    return 0;
}