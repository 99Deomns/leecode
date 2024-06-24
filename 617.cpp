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
    TreeNode* travelsal(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        if (!root1) return root2;
        if (!root2) return root1;
        root1->val += root2->val;
        root1->left = travelsal(root1->left, root2->left);
        root1->right = travelsal(root1->right, root2->right);
        return root1;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return travelsal(root1, root2);//这里也可以直接用mergeTrees作为递归函数
    }
    
};
class Solution2 {
public://这个比较巧妙，修改t1作为最后的输出，如果t1存在t2不存在，那么t1后面的部分都不需要管了
        //反之将t2赋值给t1也是一样的不需要管了
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) return t2;
        if (t2 == NULL) return t1;
        queue<TreeNode*> que;
        que.push(t1);
        que.push(t2);
        while(!que.empty()) {
            TreeNode* node1 = que.front(); que.pop();
            TreeNode* node2 = que.front(); que.pop();
            // 此时两个节点一定不为空，val相加
            node1->val += node2->val;

            // 如果两棵树左节点都不为空，加入队列
            if (node1->left != NULL && node2->left != NULL) {
                que.push(node1->left);
                que.push(node2->left);
            }
            // 如果两棵树右节点都不为空，加入队列
            if (node1->right != NULL && node2->right != NULL) {
                que.push(node1->right);
                que.push(node2->right);
            }

            // 当t1的左节点 为空 t2左节点不为空，就赋值过去
            if (node1->left == NULL && node2->left != NULL) {
                node1->left = node2->left;
            }
            // 当t1的右节点 为空 t2右节点不为空，就赋值过去
            if (node1->right == NULL && node2->right != NULL) {
                node1->right = node2->right;
            }
        }
        return t1;
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

    vector<int> inorder = { 1,3,2,5 }; TreeNode* root1 = treecreate(inorder, 0);
    vector<int> postorder = { 2,1,3,NULL,4,NULL,7 }; TreeNode* root2 = treecreate(postorder, 0);
    Solution a;
    TreeNode* res = a.mergeTrees(root1, root2);
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