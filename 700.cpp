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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        TreeNode* node = root;
        if (val == node->val) return node;
        else if (val < node->val) return searchBST(node->left, val);
        else return searchBST(node->right, val);
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
    //vector<int>nums = { 5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1 };//这里有点问题吧，尽量还是不要用层序遍历，
    //                                            //四个NULL实际写的时候可能只有两个，不好说而且一般都是输出没有null的层序遍历数组
    //TreeNode* root = treecreate(nums,0);
    //nums.insert(nums.begin(), 0);
    //TreeNode* root = Create_Tree(nums, 1);
    //LevelOrder(root);

    vector<int> inorder = { 4,2,7,1,3 }; TreeNode* root1 = treecreate(inorder, 0);
    //vector<int> postorder = { 2,1,3,NULL,4,NULL,7 }; TreeNode* root2 = treecreate(postorder, 0);
    Solution a;
    TreeNode* res = a.searchBST(root1, 5);
    LevelOrder(res);
    //for (int i = 0; i < res.size(); i++) {
    //    for (int j = 0; j < res[i].size(); j++) {
    //        cout << res[i][j] << " ";
    //    }
    //    cout << endl;
    //}
     
    //cout << res << endl;
    //vector<int> num(inorder.begin(), inorder.end()-1);
    //for (int i = 0; i < num.size(); i++) {
    //    cout << num[i] << " ";
    //}
    //cout << endl;
    return 0;
}