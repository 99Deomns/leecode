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
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right != nullptr) return false;
        if (left != nullptr && right == nullptr) return false;
        if (left == nullptr && right == nullptr) return true;
        if (left->val != right->val) return false;

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }
    bool isSymmetric_v1(TreeNode* root) {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }
    bool isSymmetric_v2(TreeNode* root) {
    if (root == nullptr) return true;
    queue<TreeNode*> que;
    que.push(root->left);
    que.push(root->right);
    while (!que.empty()) {
        TreeNode* leftNode = que.front(); que.pop();
        TreeNode* rightNode = que.front(); que.pop();
        if (!leftNode && !rightNode) continue;
        if (!leftNode || !rightNode || (leftNode->val != rightNode->val)) {
            return false;
        }
        que.push(leftNode->left); que.push(rightNode->right);
        que.push(leftNode->right); que.push(rightNode->left);
    }
    return true;
}
};

int main()
{
    TreeNode* T6 = new TreeNode(6, nullptr, nullptr);
    TreeNode* T5 = new TreeNode(5, nullptr, nullptr);
    TreeNode* T4 = new TreeNode(4, nullptr, T6);
    TreeNode* T3 = new TreeNode(3, nullptr, nullptr);
    TreeNode* T2 = new TreeNode(2, nullptr, T5);
    TreeNode* T1 = new TreeNode(1, T3, T4);
    TreeNode* root = new TreeNode(0, T1, T2);
    Solution a;
    bool res = a.isSymmetric_v1(root);
    //for (int i = 0; i < res.size(); i++) {
    //    cout << res[i] << "->";
    //}
    cout << res << endl;
    return 0;
}