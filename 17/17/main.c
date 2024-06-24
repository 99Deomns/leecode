#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int returnNum(char c) {
    if (c == '7' || c == '9') return 4;
    return 3;
}
char** letterCombinations(char* digits, int* returnSize) {
    int l = strlen(digits);
    char** ans;
    char s[8][5] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    if (l == 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 1;
    for (int i = 0; i < l; i++) {
        (*returnSize) *= returnNum(digits[i]);
    }
    ans = (char**)malloc((*returnSize) * sizeof(char*));
    int num = *returnSize;
    for (int i = 0; i < *returnSize; i++) {
        *(ans + i) = (char*)malloc((l + 1) * sizeof(char));
        ans[i][l] = '\0';
    }
    for (int i = 0; i < l; i++) {
        num /= returnNum(digits[i]);
        for (int j = 0; j < *returnSize; j++) {
            ans[j][i] = s[digits[i] - '2'][(j / num) % returnNum(digits[i])];
        }
    }
    return ans;
}
int main() {
    char* s = "23";
    int *k=0;
    char **S=letterCombinations(s, k);
    printf("%d\n", k);

    return 0;
}