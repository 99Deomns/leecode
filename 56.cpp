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
    static bool cmp(vector<int>&a, vector<int>&b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        int left = intervals[0][0], right = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); i++) {
            int curL = intervals[i][0], curR = intervals[i][1];
            if (curL <= right) {
                right = max(right, curR);
                if (i == intervals.size() - 1) {
                    res.push_back({ left,right });
                }
            }
            else{
                res.push_back({ left,right });
                left = curL, right = curR;
                if (i == intervals.size() - 1) {
                    res.push_back({ left,right });
                }
            }
        }
        
        return res;
    }
};
class Solution1 {//这个要好很多每次都更新，以免出现我写的那种还要额外一个判断
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result; // 区间集合为空直接返回
        // 排序的参数使用了lambda表达式
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0]; });

        // 第一个区间就可以放进结果集里，后面如果重叠，在result上直接合并
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] >= intervals[i][0]) { // 发现重叠区间
                // 合并区间，只更新右边界就好，因为result.back()的左边界一定是最小值，因为我们按照左边界排序的
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else {
                result.push_back(intervals[i]); // 区间不重叠 
            }
        }
        return result;
    }
};
int main()
{   
    Solution Solu;
    string s = "ababcbacadefegdehijhklij";
    vector<int> nums1 = { 5,5,5,5,10,5,10,10,10,20 };
    vector<int> nums2 = { 2,2,1,2,1 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 8;
    vector<vector<int>> people = { {1,3} ,{2,6} ,{8,10},{15,18} };
    vector<vector<int>> res = Solu.merge(people);
    cout << "answer: " << endl;
    //cout << res << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    //for (int i = 0; i < res.size(); i++) {
    //    cout << res[i] << endl;
    //}
    return 0;
}