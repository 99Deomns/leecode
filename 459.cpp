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
    void getnext(int* next, const string s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.length(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) { j++; }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }
        int len = s.size();
        vector<int> next(len);
        getnext(&next[0], s);
        if (next[len - 1] != 0 && len % (len - (next[len - 1])) == 0)
            return true;
        return false;
    }
};

int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    Solution ss;
    int res = ss.repeatedSubstringPattern(str1);
    cout << res << endl;
    return 0;
}