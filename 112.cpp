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
int index = 0;
static TreeNode* treecreate(vector<int> nums,int i) {
    if (i >= nums.size()) return nullptr;
    TreeNode* root = new TreeNode(nums[i]);
    root->left = treecreate(nums, i * 2 + 1);
    root->right = treecreate(nums, i * 2 + 2);
    return root;
}
static void LevelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    if (root) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
            if (node->val != -98167) {
                cout << node->val << "->";
            }
            else {
                cout << "NULL->";
            }
        }
    }
    cout << "NULL" << endl;
}
class Solution {
public:
    int flag = 0;
    void travsal(TreeNode* node,int sum,int target) {
        sum = sum + node->val;
        if (!node->left && !node->right && sum == target) {
            flag = 1;
            return;
        }
        if (node->left) {
            travsal(node->left, sum, target);
        }

        if (node->right) {
            travsal(node->right, sum, target);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        travsal(root,0,targetSum);
        return flag;
    }
};

int main()
{
    vector<int>nums = { 5,4,8,11,NULL,13,4,7,2,NULL,NULL,NULL,1 };
    TreeNode* root = treecreate(nums,0);
    LevelOrder(root);
    Solution a;
    bool res = a.hasPathSum(root,22);
    //for (int i = 0; i < res.size(); i++) {
    //    cout << res[i] << endl;
    //}
    cout << res << endl;
    return 0;
}