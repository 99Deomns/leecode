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

class Solution {
public:
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> que;
        for (auto it = map.begin(); it != map.end(); it++) {
            que.push(*it);
            if (que.size() > k) {
                que.pop();
            }
        }
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i]=que.top().first;
            que.pop();
        }
        return res;
    }
};

int main()
{
    vector<int> nums = { 1,1,1,2,2,3,3,3,3 };
    int k = 2;
    Solution aa;
    vector<int>res;
    res = aa.topKFrequent(nums,k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}