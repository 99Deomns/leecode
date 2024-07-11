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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int rest = 0;
        int sum = 0;
        int min = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            rest = gas[i] - cost[i];
            sum += rest;
            if (sum < min) {
                min = sum;
                start = i + 1;
            }
        }
        if (sum < 0) return -1;
        return start;
    }
};
int main()
{   
    Solution Solu;
    //string s = "101023";
    vector<int> nums1 = { 1,1,10,1,2 };
    vector<int> nums2 = { 2,2,1,2,1 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 8;
    vector<vector<char>> board;
    int res = Solu.canCompleteCircuit(nums1,nums2);
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