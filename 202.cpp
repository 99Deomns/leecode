#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <complex>
using namespace std;
class Solution {
public:
    int getsum(int n) {
        int sum = 0;
        while (n)
        {
            sum = sum + pow(n % 10, 2);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while (1) {
            int sum = getsum(n);
            if (sum == 1) return true;

            if (set.find(sum) != set.end()) {
                return false;
            }
            else {
                set.insert(sum);
            }
            n = sum;
        }
    }
};

int main() {
	Solution qq;
	
    return 0;
}