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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        if (root) Q.push(root);
        vector<vector<int>> res;
        while (!Q.empty()) {
            int size = Q.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = Q.front();
                Q.pop();
                vec.push_back(node->val);
                if (node->left)Q.push(node->left);
                if (node->right)Q.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
    void order(TreeNode* cur, vector<vector<int>>& result, int depth) {
        if (cur == nullptr) return;
        if (result.size() == depth) result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        if (cur->left) order(cur->left, result, depth+1);
        if (cur->right) order(cur->right, result, depth+1);
    }
    vector<vector<int>> levelOrder1(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        order(root, result, depth);
        return result;
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
    vector<vector<int>> res = a.levelOrder1(root);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << "->";
        }
    }

    cout << endl;
    return 0;
}