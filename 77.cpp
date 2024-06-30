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
    void backtracking(int n, int k, int start) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < n - (k - path.size())+1; i++) {
            path.push_back(i+1);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
         
    }
    vector<vector<int>> combine(int n, int k) {

        backtracking(n, k, 0);

        return res;
    }
};

int main()
{   
    Solution Solu;

    vector<vector<int>> res = Solu.combine(4, 4);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}