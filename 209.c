#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int result = INT_MAX;
    int sum = 0;
    int i = 0;//起始位置
    int sublength = 0;
    int j = 0;
    for (j = 0; j < numsSize; j++) {
        sum += nums[j];
        while (sum >= target) {
            sublength = j - i + 1;
            result = result < sublength ? result : sublength;
            sum -= nums[i++];
        }
    }
    return result == INT_MAX ? 0 : result;
}

int main() {
    int nums[] = { 2,3,1,2,4,3 };
    int n=sizeof(nums)/sizeof(int);
    int a;
    a = minSubArrayLen(7, nums, n);
    printf("%d\n", a);
    return 0;
}