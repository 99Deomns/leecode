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
    void backing(vector<int>& nums, int start) {
        res.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backing(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backing(nums, 0);
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
    vector<vector<int>> res = Solu.subsets(nums);
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