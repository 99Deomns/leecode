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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution1 {//原理其实一样但是这个代码简洁多了
public:
    // 定义一个函数，用于返回滑动窗口的最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 定义一个vector，用于存储滑动窗口的最大值
        vector<int> res;
        // 定义一个deque，用于存储滑动窗口中的下标
        deque<int> dq;
        // 遍历nums数组
        for (int i = 0; i < nums.size(); i++) {
            // 如果deque不为空，且deque的头部元素等于i-k，则弹出deque的头部元素
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            // 如果deque不为空，且nums[deque的尾部元素]小于nums[i]，则弹出deque的尾部元素
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            // 将i压入deque的尾部
            dq.push_back(i);
            // 如果i大于等于k-1，则将nums[deque的头部元素]压入res
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        // 返回res
        return res;
    }
};
class Solution {
private:
    class MyQueue {
    public:
        deque<int> que;
        void pop(int val) {
            if (!que.empty() && val == que.front()) {
                que.pop_front();
            }
        }
        void push(int val) {
            while (!que.empty() && val > que.back()) {
                que.pop_back();
            }
            que.push_back(val);
        }
        int max() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue Q;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            Q.push(nums[i]);
        }
        res.push_back(Q.max());
        for (int i = k; i < nums.size(); i++) {
            Q.pop(nums[i - k]);
            Q.push(nums[i]);
            res.push_back(Q.max());
        }
        return res;
    }
};

int main()
{
    vector<int> nums = { 1 };
    int k = 1;
    Solution aa;
    vector<int>res;
    res = aa.maxSlidingWindow(nums,k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}