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

class Solution {//有点贪心的意思，到每一个台阶花的都是最少的
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(2);
        dp[0] = 0, dp[1] = 0;
        int res = 0;
        for (int i = 2; i <= cost.size(); i++) {
            res = min(dp[0] + cost[i - 2], dp[1] + cost[i - 1]);
            dp[0] = dp[1];
            dp[1] = res;
        }
        return res;
    }
};
int main()
{   
    Solution Solu;
    string s = "ababcbacadefegdehijhklij";
    vector<int> nums1 = { 1,100,1,1,1,100,1,1,100,1 };
    vector<int> nums2 = { 2,2,1,2,1 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 10;
    vector<vector<int>> people = { {1,3} ,{2,6} ,{8,10},{15,18} };
    int res = Solu.minCostClimbingStairs(nums1);
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