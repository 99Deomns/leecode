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
            if (nums[i] > 0) break;
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }

            unordered_set<int> map;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) { // 三元组元素b去重
                    continue;
                }
                int c = -nums[i] - nums[j];
                if (map.find(c) != map.end()) {
                    res.push_back({ nums[i],nums[j],c });
                    map.erase(c);
                }
                else {
                    map.insert(nums[j]);
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
    return 0;
}