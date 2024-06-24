#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(int* nums, int numsSize, int target) {
	int begin = 0, end = numsSize - 1;
	while (begin <= end) {
		int mid = begin + (end - begin) / 2;
		if (nums[mid] > target) {
			end = mid - 1;
		}
		else if (nums[mid] < target) {
			begin = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int main() {
	int nums[] = { -1,0,3,5,9,12 };
	int a = search(nums, 6, 9);
	printf("%d\n", a);
	return 0;
}