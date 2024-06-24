#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
char* longestCommonPrefix(char** strs, int strsSize) {

    int a = strlen(strs[0]);//先获取第一个字符串的大小 怎么着公共部分都不能比第一串字符串长
    char* num = strs[0];//获取第一个字符串
    for (int j = 1; j < strsSize; j++)//这个for循环表示的行数
    {
        int i = 0;//记录第几个字节
        while (i < a && strs[j][i] == num[i])//第0行先于第1行比较然后记录多少个字节一样
        {
            i++;

        }
        a = i;//把得到的数再返回给a
    }



    num[a] = '\0';


    return num;

}


int main() {
    char s[][200] = { "flower","flow","flight" };
    printf("%d\n", 1);
    char* ret = longestCommonPrefix(s, 3);
    printf("%s\n", ret);
    return 0;
}