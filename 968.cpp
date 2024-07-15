#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits.h>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {//0未覆盖，1覆盖，2有摄像头
public:
    int res = 0;
    int travelsal(TreeNode* node) {
        if (!node) return 1;
        int left=travelsal(node->left);
        int right=travelsal(node->right);
        if (left == 0 || right == 0) {
            res++;
            return 2;
        }
        if (left == 2 || right == 2) return 1;
        if (left == 1 && right == 1) return 0;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int a = travelsal(root);
        return res + (a == 0 ? 1 : 0);
    }
};
int main()
{   
    Solution Solu;
    string s = "ababcbacadefegdehijhklij";
    vector<int> nums1 = { 5,5,5,5,10,5,10,10,10,20 };
    vector<int> nums2 = { 2,2,1,2,1 };
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    int target = 10;
    vector<vector<int>> people = { {1,3} ,{2,6} ,{8,10},{15,18} };
    TreeNode* root;
    int res = Solu.minCameraCover(root);
    cout << "answer: " << endl;
    cout << res << endl;
    //for (int i = 0; i < res.size(); i++)
    //{
    //    for (int j = 0; j < res[i].size(); j++) {
    //        cout << res[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //for (int i = 0; i < res.size(); i++) {
    //    cout << res[i] << endl;
    //}
    return 0;
}