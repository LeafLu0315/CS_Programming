#include<stdio.h>

int main()
{
    char numbers[4];
    int i=0,sum=-48*4;  //ASCII code 0=48
    for(i;i<4;i++)
        scanf("%c",&numbers[i]); //Scan every char inputs
    for(i=0;i<4;i++)
        sum+=numbers[i];    //sum+ numbers of ASCII code
    printf("%d",sum);
    return 0;
}
