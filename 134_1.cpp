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
        for (int i = 0; i < gas.size(); i++) {
            int leftGas = gas[i]-cost[i];
            int cur = (i + 1) % gas.size();
            while (leftGas>0 && cur != i) {
                leftGas += gas[cur] - cost[cur];
                cur = (cur + 1) % gas.size();
            }
            if (leftGas>=0&&cur==i) return i;
        }
        return -1;
    }
};
int main()
{   
    Solution Solu;
    //string s = "101023";
    vector<int> nums1 = { 1,2,3,4,5 };
    vector<int> nums2 = { 3,4,5,1,2 };
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