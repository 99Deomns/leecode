
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

class Solution{
public:
    vector<string> res;
    string path;
    bool isValid(string s, int start, int end) {
        if (start > end) {
            return false;
        }
        else if (s[start] == '0' && start != end) {
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            num = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
    void backing(string s, int start,int k) {
        if (k == 3) {
            if (isValid(s, start, s.size() - 1)) {
                for (int i = start; i <= s.size() - 1; i++) {
                    path.push_back(s[i]);
                }
                res.push_back(path);
            }
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isValid(s, start, i)) {
                for (int j = start; j <= i; j++) {
                    path.push_back(s[j]);
                }
                path += '.';
                k++;
                backing(s, i + 1, k);
                k--;
                if (k == 2 && isValid(s, i + 1, s.size() - 1)) {
                    for (int ii = i+1; ii <= s.size() - 1; ii++) {
                        path.pop_back();
                    }
                }
                for (int k = 0; k <= i - start + 1; k++) {
                    path.pop_back();
                }
            }
            else break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backing(s, 0, 0);
        return res;
    }
};

int main()
{   
    Solution Solu;
    string s = "101023";
    vector<int> nums = { 2,5,2,1,2 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 5;
    vector<string> res = Solu.restoreIpAddresses(s);
    cout << "answer: " << endl;
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