#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
char* longestCommonPrefix(char** strs, int strsSize) {

    int a = strlen(strs[0]);//�Ȼ�ȡ��һ���ַ����Ĵ�С ��ô�Ź������ֶ����ܱȵ�һ���ַ�����
    char* num = strs[0];//��ȡ��һ���ַ���
    for (int j = 1; j < strsSize; j++)//���forѭ����ʾ������
    {
        int i = 0;//��¼�ڼ����ֽ�
        while (i < a && strs[j][i] == num[i])//��0�����ڵ�1�бȽ�Ȼ���¼���ٸ��ֽ�һ��
        {
            i++;

        }
        a = i;//�ѵõ������ٷ��ظ�a
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