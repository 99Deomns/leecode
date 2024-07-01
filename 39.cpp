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
    void backing(vector<int>& nums,int last,int start) {
        if (last == 0) {
            res.push_back(path);
            return;
        }
        else if (last < 0) {
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backing(nums, last - nums[i],i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backing(candidates, target,0);

        return res;
    }
};

int main()
{   
    Solution Solu;
    string s = "";
    vector<int> nums = { 2,3,5 };
    int target = 8;
    vector<vector<int>> res = Solu.combinationSum(nums, target);
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