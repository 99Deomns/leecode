#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int index1 = 0, index2 = len-1;
        int index = 0;
        int a = 0;
        int num = 0;
        int maxnum = 1;
        string out;
        out.resize(1);
        out[0] = s[0];
        if (len == 1) {
            return out;
        }
        
        for (index = 0; index < len-1; index++){
            index1 = index;
            index2 = len - 1;
            num = 0;
            a = index2;
            while (index1 < index2) {
                if (s[index1] == s[index2]) {
                    index1++;
                    index2--;
                    num += 2;
                }
                else {
                    index1 = index;
                    a--;
                    index2 = a;
                    num = 0;
                }
            }
            if (index1 == index2) num = num + 1;
            if (num > maxnum) {
                out.resize(num);
                maxnum = num;
                for (int i = 0; i < num; i++) {
                    out[i] = s[index + i];
                    //cout << s[index + i];
                }
            }
        }
        return out;
    }
};

int main() {
    string s = "aacabdkacaa";
    Solution problem;
    string out=problem.longestPalindrome(s);
    cout << out << endl;
    return 0;
}