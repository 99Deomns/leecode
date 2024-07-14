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
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])return a[1] < b[1];
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int curL = intervals[i][0], curR = intervals[i][1];
            if (curL == left) {
                res++;
            }
            else if(curL<right){
                res++;
                if (right > curR) {
                    left = intervals[i][0], right = intervals[i][1];
                }
            }
            else {
                left = intervals[i][0], right = intervals[i][1];
            }
        }
        return res;
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
    vector<vector<int>> people = { {0,2} ,{1,3} ,{2,4} ,{3,5},{4,6} };
    int res = Solu.eraseOverlapIntervals(people);
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