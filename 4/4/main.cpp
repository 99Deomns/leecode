#include "Solution.h"

int main() {
	vector<int>nums1 = {1};
	vector<int>nums2 = {2,3,4,5,6};
	Solution a;
	double cc=a.findMedianSortedArrays(nums1, nums2);
	cout << cc << endl;

	return 0;
}