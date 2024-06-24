#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string changenum(string s) {
        int i = 0;
        string res;
        string num = "number";
        while (i < s.length()) {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                res += num;
            }
            else {
                res.push_back(s[i]);
            }
            i++;
        }
        return res;
    }
};

int main()
{
    string str;
    //cout << "输入: ";
    //getline(cin, str);
    cin >> str;
    Solution ss;
    string sss = ss.changenum(str);
    cout << sss;
    return 0;
}