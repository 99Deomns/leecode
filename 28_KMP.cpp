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
    int strStr(string haystack, string needle) {
        vector<int> next(needle.size());
        getnext(&next[0], needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }
        
        return -1;
    }
};

int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    Solution ss;
    int res = ss.strStr(str1,str2);
    cout << res;
    return 0;
}