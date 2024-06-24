#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int  x1 = 0;
        while (x) {
            int tmp = x % 10;
            if (x1 > 214748364 || (x1 == 214748364 && tmp > 7)) {
                return 0;
            }
            //判断是否 小于 最小32位整数
            if (x1 < -214748364 || (x1 == -214748364 && tmp < -8)) {
                return 0;
            }
            x1 = x1 * 10 + tmp;
            
            x = x / 10;
        }
        return x1;
    }
};

int main() {
    Solution a;
    int x = 1534236469;
    int x1 = a.reverse(x);
    cout << x1 << endl;
    return 0;
}