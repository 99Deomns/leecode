#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits.h>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {//递归法也能用但是会超时
public:
    bool backing(vector<int>& nums, int start) {
        if (nums[start] >= nums.size() - start - 1) return true;
        for (int i = nums[start]; i > 0; i--) {
            int res = backing(nums, start+i);
            if (res) return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        bool res = backing(nums, 0);
        return res;
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int cover = 0;
        for (int i = 0; i <= cover; i++) {
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size()-1) {
                return true;
            }
        }
        return false;
    }
};


int main()
{   
    Solution Solu;
    //string s = "101023";
    vector<int> nums = { 3,2,1,0,4 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 5;
    vector<vector<char>> board;
    bool res = Solu.canJump(nums);
    cout << "answer: " << endl;
    cout << res << endl;
    //for (int i = 0; i < res.size(); i++)
    //{
    //    for (int j = 0; j < res[i].size(); j++) {
    //        cout << res[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //for (int i = 0; i < res.size(); i++) {
    //    cout << res[i] << endl;
    //}
    return 0;
}