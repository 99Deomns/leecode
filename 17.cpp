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
const string letterMap[10] = {
    "",
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
};
class Solution {
public:
    vector<string>res;
    string path;
    void backing(string digits,int index) {
        int size = digits.size();
        if (size == 0) return;
        if (index == size) {
            res.push_back(path);
            return;
        }
        int num = digits[index] - '0';
        for (int i = 0; i < letterMap[num].size(); i++) {
            path += letterMap[num][i];
            backing(digits, index + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        backing(digits, 0);
        return res;
    }
};

int main()
{   
    Solution Solu;
    string s = "";
    vector<string> res = Solu.letterCombinations(s);
    //for (int i = 0; i < res.size(); i++)
    //{
    //    for (int j = 0; j < res[i].size(); j++) {
    //        cout << res[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}