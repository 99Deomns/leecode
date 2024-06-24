#include "Solution.h"

int Solution::findKthdata(vector<int>& nums1, vector<int>& nums2, int k)
{
    int num1 = nums1.size(), num2 = nums2.size();
    int index1 = 0, index2 = 0;
    while (true)
    {
        if (index1 == num1) {
            return nums2[index2 + k - 1];
        }
        if (index2 == num2) {
            return nums1[index1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[index1], nums2[index2]);
        }
        int newIndex1 = min(index1 + k / 2 - 1, num1-1);
        int newIndex2 = min(index2 + k / 2 - 1, num2-1);
        int data1 = nums1[newIndex1];
        int data2 = nums2[newIndex2];
        if (data1 <= data2) {
            k -= newIndex1 - index1 + 1;
            index1 = newIndex1 + 1;
        }
        else {
            k -= newIndex2 - index2 + 1;
            index2 = newIndex2 + 1;
        }
    }
}


double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int num = nums1.size() + nums2.size();
    if (num % 2) {
        return findKthdata(nums1, nums2, (num + 1) / 2);
    }
    else {
        cout << findKthdata(nums1, nums2, num / 2) << " " << findKthdata(nums1, nums2, num / 2 + 1) << endl;
        return (findKthdata(nums1, nums2, num / 2) + findKthdata(nums1, nums2, num / 2 + 1)) / 2.0;
    }
}

