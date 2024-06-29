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
bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)return root;
        if (root->val == key) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            if (!root->left && root->right) {
                auto res = root->right;
                delete root;
                return res;
            }
            if (root->left && !root->right) {
                auto res = root->left;
                delete root;
                return res;
            }
            if (root->left && root->right) {
                auto node = root->right;
                while (node->left) {
                    node = node->left;
                }
                node->left = root->left;
                return root->right;
            }
        }
        if (root->val > key)root->left = deleteNode(root->left, key);
        if (root->val < key)root->right = deleteNode(root->right, key);
        return root;
    }
};
//TreeNode* Create_Tree(vector<int>& l_nums, int i) //层次遍历创建二叉树
//{
//    if (i >= l_nums.size() || l_nums[i] == 0) //数值为0或超出数组范围
//        return nullptr;
//    TreeNode* root = new TreeNode(l_nums[i]);
//    root->left = Create_Tree(l_nums, i * 2);
//    root->right = Create_Tree(l_nums, i * 2 + 1);
//    return root;
//}
int main()
{

    vector<int> inorder = { }; TreeNode* root1 = treecreate(inorder, 0);
    //vector<int> postorder = { 2,1,3,NULL,4,NULL,7 }; TreeNode* root2 = treecreate(postorder, 0);
    Solution a;
    TreeNode* res = a.deleteNode(root1,5);
    LevelOrder(res);
    //for (int i = 0; i < res.size(); i++) {
    //    for (int j = 0; j < res[i].size(); j++) {
    //        cout << res[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << res << endl;
    //cout << res << endl;
    //vector<int> num(inorder.begin(), inorder.end()-1);
    //for (int i = 0; i < res.size(); i++) {
    //    cout << res[i] << " ";
    //}
    cout << endl;
    return 0;
}