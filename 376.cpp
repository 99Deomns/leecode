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
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 2&&nums[0]!=nums[1]) return 2;
        if (nums.size() == 2 && nums[0] == 0) {
            return 1;
        }
        if (nums.size() == 1) return 1;
        vector<int> minus;
        int res = nums.size();
        minus.resize(res-1);
        for (int i = 0; i < res-1; i++) {
            minus[i] = nums[i + 1] - nums[i];
        }
        int i = 0;
        int last;
        for (; i < minus.size(); i++) {
            last = minus[i];
            if (last == 0) {
                res--;
                if (i == minus.size() - 1) {
                    return res;
                }
                continue;
            }
            else {
                break;
            }
        }
        for ((i=i==0?1:i+1); i < minus.size(); i++) {
            if (last*minus[i] < 0){
                last = minus[i];
            }
            else if (last * minus[i] >= 0) {
                res--;
            }
        }
        return res;
    }
};

int main()
{   
    Solution Solu;
    //string s = "101023";
    vector<int> nums = { 3,3,3,2,5 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 5;
    vector<vector<char>> board;
    int res = Solu.wiggleMaxLength(nums);
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