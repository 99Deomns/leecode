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
    int max_depth = -1;
    int result = 0;
    void travsal(TreeNode* node, int depth) {
        if (node == nullptr) return;
        if (depth > max_depth) {
            max_depth = depth;
            result = node->val;
        }
        
        travsal(node->left, depth+1);
        travsal(node->right, depth+1); 

    }
    int findBottomLeftValue(TreeNode* root) {
        travsal(root, 0);
        return result;
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
    int res = a.findBottomLeftValue(root);
    //for (int i = 0; i < res.size(); i++) {
    //    cout << res[i] << endl;
    //}
    cout << res << endl;
    return 0;
}