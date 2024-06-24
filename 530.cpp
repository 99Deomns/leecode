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
            if (node->val != NULL) {
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
    //进行中序遍历，使得遍历的元素从小到大
    int res = INT_MAX;
    TreeNode* pre = nullptr;
    void travelsal(TreeNode* root) {
        if (!root) return;
        travelsal(root->left);
        if (pre) res = min(res, root->val - pre->val);
        pre = root;
        travelsal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        travelsal(root);
        return res;
    }

};

int main()
{

    vector<int> inorder = { 4,2,6,1,3 }; TreeNode* root1 = treecreate(inorder, 0);
    Solution a;
    bool res = a.getMinimumDifference(root1);
    cout << res << endl;
    return 0;
}