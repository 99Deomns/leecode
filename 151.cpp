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
    string removeSpace(string s) {
        string res;
        res.resize(s.length());
        int slow = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && slow != 0) {
                res[slow++] = ' ';
            }
            while (s[i] != ' '&&i<s.length()) {
                res[slow++] = s[i++];
            }
        }
        res.resize(slow);
        cout << res.size() << endl;
        return res;
    }
    string reverseWords(string s) {
        string res;
        cout <<"最开始："<< s << endl;
        reverse(s.begin(), s.end());
        cout << "翻转后：" << s << endl;
        res = removeSpace(s);
        cout << "去空格：" << res << endl;
        int start = 0, end = 0;
        for (int i = 0; i < res.length(); i++) {
            start = i, end = i;
            while (res[i] != ' ' && i < res.length()) {
                i++;
            }
            end = i;
            reverse(res.begin() + start, res.begin() +end);
            cout << "每次翻转单词：" << res << endl;
        }
        return res;
    }
};

int main()
{
    string str;
    //cout << "输入: ";
    //getline(cin, str);
    str = " hg hkf i higfgi  gi  ikbf    ";
    Solution ss;
    string sss = ss.reverseWords(str);
    cout << sss;
    return 0;
}