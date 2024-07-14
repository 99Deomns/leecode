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
    vector<int> partitionLabels(string s) {
        vector<int> direction(26);
        for (int i = 0; i < s.size(); i++) {
            direction[s[i] - 'a'] = i;
        }
        vector<int> res;
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, direction[s[i] - 'a']);
            if (i == right) {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
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
    vector<vector<int>> people = { {0,2} ,{1,3} ,{2,4} ,{3,5},{4,6} };
    vector<int> res = Solu.partitionLabels(s);
    cout << "answer: " << endl;
    //cout << res << endl;
    //for (int i = 0; i < res.size(); i++)
    //{
    //    for (int j = 0; j < res[i].size(); j++) {
    //        cout << res[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}