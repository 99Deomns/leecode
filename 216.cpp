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
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int k, int last,int start) {
        if (last < 0) return;
        if (path.size() == k) {
            if(last==0) res.push_back(path);
            return;
         }
        for (int i = start; i < 9 - (k - path.size()) + 1; i++) {
            path.push_back(i + 1);
            backtracking(k, last - i - 1,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        backtracking(k, n, 0);

        return res;
    }
};

int main()
{   
    Solution Solu;

    vector<vector<int>> res = Solu.combinationSum3(3, 9);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}