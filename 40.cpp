#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <deque>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int>path;
    void backing(vector<int>& nums, int last, int start) {
        if (last == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < nums.size() && last - nums[i] >= 0; i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backing(nums, last - nums[i], i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backing(candidates, target, 0);

        return res;
    }
};

int main()
{   
    Solution Solu;
    string s = "";
    vector<int> nums = { 2,5,2,1,2 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 5;
    vector<vector<int>> res = Solu.combinationSum2(nums, target);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    //for (int i = 0; i < res.size(); i++) {
    //    cout << res[i] << " ";
    //}
    return 0;
}