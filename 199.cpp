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


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left)que.push(node->left);
                if (node->right)que.push(node->right);
                if (i == size - 1)res.push_back(node->val);
            }
        }
        return res;
    }
};

int main()
{
    TreeNode* T6 = new TreeNode(6, nullptr, nullptr);
    TreeNode* T5 = new TreeNode(5, nullptr, nullptr);
    TreeNode* T4 = new TreeNode(4,nullptr,T6);
    TreeNode* T3 = new TreeNode(3, nullptr, nullptr);
    TreeNode* T2 = new TreeNode(2,nullptr,T5);
    TreeNode* T1 = new TreeNode(1, T3, T4);
    TreeNode* root = new TreeNode(0,T1, T2);
    Solution a;
    vector<int> res = a.levelOrderBottom(root);
    for (int j = 0; j < res.size(); j++) {
        cout << res[j] << "->";
    }
    //for (int i = 0; i < res.size(); i++) {
    //    for (int j = 0; j < res[i].size(); j++) {
    //        cout << res[i][j] << "->";
    //    }
    //}


    cout << endl;
    return 0;
}