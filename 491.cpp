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
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int last = INT_MIN;

    void backing(vector<int>& nums, int start) {
        if (path.size() >= 2) {
            res.push_back(path);
        }
        vector<int>used;
        for (int i = start; i < nums.size(); i++) {
            if (i != start && find(used.begin(), used.end(), nums[i]) != used.end()) continue;
            if (!path.empty()) last = path[path.size() - 1];
            else last = INT_MIN;
            if (nums[i] >= last) {
                path.push_back(nums[i]);
                used.push_back(nums[i]);
                backing(nums, i + 1);
                path.pop_back();
                //used.pop_back();这个不能有啊，此时used记录的是遍历中指定位置不能重复
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backing(nums, 0);
        return res;
    }
};
int main()
{   
    Solution Solu;
    string s = "101023";
    vector<int> nums = { 4,6,7,7 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 5;
    vector<vector<int>> res = Solu.findSubsequences(nums);
    cout << "answer: " << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    //for (int i = 0; i < res.size(); i++) {
    //    cout << res[i] << endl;
    //}
    return 0;
}