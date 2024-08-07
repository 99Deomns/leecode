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
    bool lemonadeChange(vector<int>& bills) {
        vector<int> nums(2, 0);
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) nums[0]++;
            else if (bills[i] == 10) {
                nums[1]++;
                nums[0]--;
                if (nums[0] < 0) return false;
            }
            else if (bills[i] == 20) {
                if (nums[1]) {
                    nums[1]--;
                    nums[0]--;
                    if (nums[0] < 0) return false;
                }
                else {
                    nums[0] -= 3;
                    if (nums[0] < 0) return false;
                }
            }
        }
        return true;
    }
};
int main()
{   
    Solution Solu;
    //string s = "101023";
    vector<int> nums1 = { 5,5,5,5,10,5,10,10,10,20 };
    vector<int> nums2 = { 2,2,1,2,1 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 8;
    vector<vector<char>> board;
    int res = Solu.lemonadeChange(nums1);
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