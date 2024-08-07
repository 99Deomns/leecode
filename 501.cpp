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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;
        vector<int>res;
        stack<TreeNode*> st;
        if (root) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node) {
                st.pop();
                if (node->right)st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if (node->left) st.push(node->left);
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                map[node->val]++;
            }
        }
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(),cmp);
        res.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].second == vec[0].second) {
                res.push_back(vec[i].first);
            }
            else
                break;
        }
        return res;
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

    vector<int> inorder = { 1,NULL,2,2 }; TreeNode* root1 = treecreate(inorder, 0);
    //vector<int> postorder = { 2,1,3,NULL,4,NULL,7 }; TreeNode* root2 = treecreate(postorder, 0);
    Solution a;
    vector<int> res = a.findMode(root1);
    //LevelOrder(res);
    //for (int i = 0; i < res.size(); i++) {
    //    for (int j = 0; j < res[i].size(); j++) {
    //        cout << res[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << res << endl;
    //cout << res << endl;
    //vector<int> num(inorder.begin(), inorder.end()-1);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}