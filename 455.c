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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int size = 0;
        int res = 0;
        for (int i = 0; i < g.size() && size < s.size() && res < s.size(); i++) {
            while (size < s.size() && s[size] < g[i]) {
                size++;
            }
            if (size < s.size() && s[size] >= g[i]) {
                res++;
                size++;
            }
        }
        return res;

    }
    
};

int main()
{   
    Solution Solu;
    //string s = "101023";
    vector<int> nums = { 4,6,7,7 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 5;
    vector<vector<char>> board;
    vector<int> g = { 1,2,3 };
    vector<int> s = { 3};
    int res = Solu.findContentChildren(g, s);
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