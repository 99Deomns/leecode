#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <deque>
#include <queue>
#include <limits.h>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    vector < vector<string>> res;
    vector<string> path;
    bool isP(const string s, int start, int end) {
        string s1 = s.substr(start, end-start);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        if (s1 == s2) return true;
        return false;
    }
    void backing(string s, int start) {
        if (start >= s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isP(s, start, i + 1)) {
                string str = s.substr(start, i + 1 - start);
                path.push_back(str);
            }
            else {
                continue;
            }
            backing(s, i + 1);
            path.pop_back();
        }

    }
    vector<vector<string>> partition(string s) {

        backing(s, 0);
        return res;
    }
};

int main()
{   
    Solution Solu;
    string s = "aab";
    vector<int> nums = { 2,5,2,1,2 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 5;
    vector<vector<string>> res = Solu.partition(s);
    cout << "answer: " << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    //for (int i = 0; i < res.size(); i++) {
    //    cout << res[i] << " ";
    //}
    return 0;
}