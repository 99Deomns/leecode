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
    int maxProfit(vector<int>& prices) {
        int res = 0;
        vector<int> profit(prices.size() - 1);
        for (int i = 0; i < profit.size(); i++) {
            profit[i] = prices[i + 1] - prices[i];
            if (profit[i] > 0) res += profit[i];
        }
        return  res;
    }
};

int main()
{   
    Solution Solu;
    //string s = "101023";
    vector<int> nums = { 7,1,5,3,6,4 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 5;
    vector<vector<char>> board;
    int res = Solu.maxProfit(nums);
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