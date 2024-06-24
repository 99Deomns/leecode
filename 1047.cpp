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
    string removeDuplicates(string s) {
        stack<char> st;
        for (int j = 0; j < s.size(); j++) {
            if (!j) {
                st.push(s[j]);
                continue;
            }
            if (st.size()!=0&&st.top() == s[j]) {
                st.pop();
            }
            else {
                st.push(s[j]);
            }
        }

        string res;
        int len = st.size();
        for (int i = 0; i < len; i++) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    string s = "azxxzy";
    Solution aa;
    string res = aa.removeDuplicates(s);
    cout << res << endl;

    return 0;
}