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
    int strStr(string haystack, string needle) {
        int fast = 0, low = 0;
        int res = 0;
        for (int i = 0; i < haystack.length(); i++) {
            fast = i;
            if (haystack[fast] == needle[low]) {
                res = fast;
                fast++; low++; 
                while (haystack[fast] == needle[low] && fast < haystack.length() && low < needle.length()) {
                    fast++; low++;
                }
                if (low == needle.length()) return res;
                else {
                    low = 0;
                }
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