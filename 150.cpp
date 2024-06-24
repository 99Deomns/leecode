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
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long a2 = st.top();
                st.pop();
                long long a1 = st.top();
                st.pop();
                if (tokens[i] == "+") {
                    st.push(a1 + a2);
                }
                else if (tokens[i] == "-") {
                    st.push(a1 - a2);
                }
                else if (tokens[i] == "*") {
                    st.push(a1 * a2);
                }
                else if (tokens[i] == "/") {
                    st.push(a1 / a2);
                }
            }
            else {
                st.push(stoll(tokens[i]));
            }
        }
        int res = st.top();
        st.pop();
        return res;
    }
};

int main()
{
    vector<string> st = { "4","13","5","/","+" };
    Solution aa;
    long long  res = aa.evalRPN(st);
    cout << res << endl;
    return 0;
}