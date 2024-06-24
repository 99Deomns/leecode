#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for(char c : s) {
            rows[i].push_back(c);
            if (i == numRows-1||i==0)
                flag = -flag;
            i += flag;
        }
        string res;
        for (string& row : rows) {
            res += row;
        }
        return res;
    }
};

int main() {
    string s = "PAYPALISHIRING";
    Solution a;
    a.convert(s, 3);
    cout << s << endl;
    return 0;
}