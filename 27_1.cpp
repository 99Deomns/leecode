#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int sum = 0;
        int i = 0;
        for (i = 0; i < len; ) {
            if (nums[i] == val) {
                for (int j = i; j<len-1; j++) {
                    nums[j] = nums[j + 1];
                }
                len = len - 1;
                nums.resize(len);
                
            }
            else {
                sum++;
                i++;
            }
        }
        nums.resize(i);
        return sum;
    }
};



int main()
{
    string str1, str2;
    Solution ss;
    vector<int> num = { 0,1,2,2,3,0,4,2 };
    int val = 2;
    int res = ss.removeElement(num,val);
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    cout << res << endl;
    return 0;
}