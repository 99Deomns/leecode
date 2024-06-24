#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/***************************************************************/
void PreOrderRecur(TreeNode *root, vector<int> &nodes)
{ //先序遍历，递归法(Recursion) 根-左-右
    if (!root)
        return;
    nodes.emplace_back(root->val);
    PreOrderRecur(root->left, nodes);
    PreOrderRecur(root->right, nodes);
}

void PreOrderIter(TreeNode *root, vector<int> &nodes)
{ //先序遍历，迭代法(Iteration) 根-左-右
    stack<TreeNode *> stk;
    while (root || !stk.empty())
    {
        while (root)
        {
            nodes.emplace_back(root->val);
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        root = root->right;
    }
}
/***************************************************************/
void InOrderRecur(TreeNode *root, vector<int> &nodes)
{ //中序遍历，递归法(Recursion) 左-根-右
    if (!root)
        return;
    InOrderRecur(root->left, nodes);
    nodes.emplace_back(root->val);
    InOrderRecur(root->right, nodes);
}

void InOrderIter(TreeNode *root, vector<int> &nodes)
{ //中序遍历，迭代法(Iteration) 左-根-右
    stack<TreeNode *> stk;
    while (root || !stk.empty())
    {
        while (root)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        nodes.emplace_back(root->val);
        root = root->right;
    }
}
/***************************************************************/
void PosOrderRecur(TreeNode *root, vector<int> &nodes)
{ //后序遍历，递归法(Recursion) 左-右-根
    if (!root)
        return;
    PosOrderRecur(root->left, nodes);
    PosOrderRecur(root->right, nodes);
    nodes.emplace_back(root->val);
}

void PosOrderIter(TreeNode *root, vector<int> &nodes)
{ //后序遍历，迭代法(Iteration) 左-右-根
    stack<TreeNode *> stk;
    TreeNode *prev = nullptr;
    while (root || !stk.empty())
    {
        while (root)
        {
            stk.push(root);
            root = root->left; //到最左边
        }
        root = stk.top();
        //判断是否有右边的下一层以及右边是否访问过
        if (root->right && root->right != prev)
            root = root->right;
        else
        {
            stk.pop();
            nodes.emplace_back(root->val);
            prev = root;
            root = nullptr;
        }
    }
}
/***************************************************************/
void LevelOrderIter(TreeNode *root, vector<vector<int>> &levels)
{ //层序遍历，迭代法(Iteration)
    if (!root)
        return;
    queue<TreeNode *> que;
    que.emplace(root);
    while (!que.empty())
    {
        int sz = que.size(); //关键，取队列在此时的大小，以决定循环次数
        vector<int> level;
        for (int i = 0; i < sz; ++i)
        { //进入循环
            level.emplace_back(que.front()->val);
            if (que.front()->left)
                que.emplace(que.front()->left);
            if (que.front()->right)
                que.emplace(que.front()->right);
            que.pop();
        }
        levels.emplace_back(level);
    }
}
/***************************************************************/
TreeNode *Create_Tree(vector<int> &l_nums, int i) //层次遍历创建二叉树
{
    if (l_nums[i] == 0 || i >= l_nums.size()) //数值为0或超出数组范围
        return nullptr;
    TreeNode *root = new TreeNode(l_nums[i]);
    root->left = Create_Tree(l_nums, i * 2);
    root->right = Create_Tree(l_nums, i * 2 + 1);
    return root;
}

/***************************************************************/
int main()
{
    /*二叉树
        1
       / \
      3   2
     /\    \
    4  5    9
    先序遍历：先遍历根节点，再遍历左子树，最后遍历右子树（根-左-右）// 1 3 4 5 2 9
    中序遍历：先遍历左子树，再遍历根节点，最后遍历右子树（左-根-右）// 4 3 5 1 2 9
    后序遍历：先遍历左子树，再遍历右子树，最后遍历根节点（左-右-根）// 4 5 3 9 2 1
    层序遍历：从上到下逐层、从左到右遍历 // 1; 3 2; 4 5 9
    */
    vector<int> level_nums = {1, 3, 2, 4, 5, 0, 9};               //层次数组
    level_nums.insert(level_nums.begin(), 0);                     //头部插入一个0
    TreeNode *tree = Create_Tree(level_nums, 1);                  //从下标1开始用，层次遍历值创建二叉树
    level_nums.erase(level_nums.begin(), level_nums.begin() + 1); //删除头部的0

    vector<int> pr, in, po;      //先序、中序、后序遍历输出存储数组
    vector<vector<int>> level;   //层序遍历输出存储数组
    PreOrderRecur(tree, pr);     // 1 3 4 5 2 9
    InOrderRecur(tree, in);      // 4 3 5 1 2 9
    PosOrderIter(tree, po);      // 4 5 3 9 2 1
    LevelOrderIter(tree, level); // 1; 3 2; 4 5 9

    return 0;
}
