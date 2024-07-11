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

class Solution {
public:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int res=0;
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k>0) {
                nums[i] = nums[i] < 0 ? (-nums[i]) : nums[i];
                k--;
            }
        }
        if (k % 2) nums[nums.size() - 1] *= -1;
        for (int a : nums) res += a;
        
        return res;
    }
};
int main()
{   
    Solution Solu;
    //string s = "101023";
    vector<int> nums = { 8,-7,-3,-9,1,9,-6,-9,3 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 8;
    vector<vector<char>> board;
    int res = Solu.largestSumAfterKNegations(nums,target);
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