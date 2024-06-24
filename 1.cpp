#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto tar = map.find(target - nums[i]);
            if (tar != map.end()) {
                return { tar->second,i };
            }
            else {
                map.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums = { 2,7,11,15 };
	Solution qq;
    vector<int> res = qq.twoSum(nums, 18);
    printf("%d %d \n", res[0], res[1]);
    return 0;
}