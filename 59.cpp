#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startX = 0, startY = 0;
        int loop = n / 2;
        int mid = n / 2;
        int count = 1;
        int offset = 1;
        int i, j;
        while (loop--) {
            i = startX;
            j = startY;
            for (; j < n - offset; j++) {
                res[i][j] = count++;
            }
            for (; i < n - offset; i++) {
                res[i][j] = count++;
            }
            for (;j > startY; j--)
            {
                res[i][j] = count++;
            }
            for (; i > startX; i--) {
                res[i][j] = count++;
            }
            startX++;
            startY++;
            offset++;
        }
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};

int main() {
    Solution ans;
    int n = 6;
    vector<vector<int>> res(n, vector<int>(n, 0));
    res = ans.generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            cout << res[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}