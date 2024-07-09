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
    vector<vector<string>> res;
    void backing(int n,int row,vector<string>&chessboard) {
        if (row == n) {
            res.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, chessboard, n)) {
                chessboard[row][col] = 'Q';
                backing(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }
    bool isValid(int row,int col,vector<string>& chessboard,int n) {
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>chessboard(n, string(n, '.'));
        backing(n, 0, chessboard);
        return res;
    }
};
int main()
{   
    Solution Solu;
    string s = "101023";
    vector<int> nums = { 4,6,7,7 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 5;
    vector<vector<string>> tickets = { {"MUC","LHR"}, {"JFK","MUC"}, {"SFO","SJC"}, {"LHR","SFO"} };
    vector<vector<string>> res = Solu.solveNQueens(target);
    cout << "answer: " << endl;
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