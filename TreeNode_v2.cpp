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
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        //traversal(root, result);//遍历法
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node) {
                st.pop();
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
                st.push(node);
                st.push(nullptr);
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*>st;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node) {
                st.pop();
                if (node->right) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if (node->left)st.push(node->left);
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        
        return res;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node) {
                st.push(nullptr);
                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左

            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
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
    vector<int> res = a.postorderTraversal(root);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "->";
    }
    cout << endl;
    return 0;
}