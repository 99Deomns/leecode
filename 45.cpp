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
    int jump(vector<int>& nums) {
        int res = 0;
        if (nums.size() == 1) return 0;
        int past = 0;
        int newL = 0;
        for (int i = 0; i < nums.size(); i++) {
            newL = max(nums[i] + i , newL);
            if (i == past) {
                past = newL;
                res++;
                if (newL >= nums.size()-1) {
                    return res;
                }
            }
        }
    }
};
int main()
{   
    Solution Solu;
    //string s = "101023";
    vector<int> nums = { 2,3,0,1,4 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 5;
    vector<vector<char>> board;
    int res = Solu.jump(nums);
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