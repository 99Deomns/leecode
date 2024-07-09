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
    vector<int> used;
    void backing(vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size() ; i++) {
            if ((find(used.begin(), used.end(), nums[i]) != used.end()))continue;
            path.push_back(nums[i]);
            used.push_back(nums[i]);
            backing(nums);
            used.pop_back();
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backing(nums);
        return res;
    }
};
int main()
{   
    Solution Solu;
    string s = "101023";
    vector<int> nums = {1,2,3};
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 5;
    vector<vector<int>> res = Solu.permute(nums);
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