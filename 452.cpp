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
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int res = 0;
        int left = points[0][0], right = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            int curL = points[i][0], curR = points[i][1];
            if (curL <= right) {
                left = curL;
                right = min(right, curR);
            }
            else {
                res++;
                left = points[i][0], right = points[i][1];
            }
        }
        return res+1;
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
    vector<vector<int>> people = { {10,16} ,{2,8},{1,6},{7,12}};
    int res = Solu.findMinArrowShots(people);
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