#include <stdio.h>

int main()
{
    float ddd = 66.67;
    char buffer[10];
    sprintf(buffer, "%f", ddd);//The value of ddd = 666
    printf("%s\n",buffer);
    //ddd = 666;
    //sprintf(buffer, "%f", ddd);
    //printf("%d", strlen(buffer));
    return 0;
}