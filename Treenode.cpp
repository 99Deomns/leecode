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
        if (root == nullptr) return res;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->right)st.push(node->right);
            if (node->left)st.push(node->left);
        }
        return res;
    }//访问与处理的顺序不一样
    vector<int> inorderTraversal(TreeNode* root) {//中序遍历要先找到最左边的,与其他两种最大的不同是，其他的可以一边访问根节点，同时处理根节点，但是对于中序遍历来说访问的是根节点，但是第一个处理的是最左边的节点
        vector<int> res;
        stack<TreeNode*>st;
        if (root == nullptr) return res;
        TreeNode* node = root;
        while (node!=nullptr||!st.empty()) {
            if (node) {
                st.push(node);
                node = node->left;
            }
            else {
                node = st.top();
                st.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
    vector<int> postorderTraversal(TreeNode* root) {//与前序遍历类似前序遍历是根左右，改为根右左，然后逆序输出，就是左右根
        vector<int> res;
        //traversal(root, result);//遍历法
        stack<TreeNode*> st;
        if (root == nullptr) return res;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->left)st.push(node->left);
            if (node->right)st.push(node->right);
        }
        reverse(res.begin(), res.end());
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
    vector<int> res = a.inorderTraversal(root);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "->";
    }
    cout << endl;
    return 0;
}