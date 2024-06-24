#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        if (s.size() % 2) return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') sta.push(')');
            else if (s[i] == '[') sta.push(']');
            else if (s[i] == '{') sta.push('}');
            else if (sta.empty() || sta.top() != s[i]) return false;
            else sta.pop();
        }
        return sta.empty();
    }

};


int main()
{
    string s = "()[]{}";
    Solution aa;
    bool res = aa.isValid(s);
    cout << res << endl;

    return 0;
}