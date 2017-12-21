#include<stdio.h>
int main()
{
    int coins=0;
    scanf("%d",&coins);  //Read how many coins

    int temp=coins/50;  //How many 50s can coins change
    printf("%d\n",temp);  //output how many 50s
    coins-=temp*50;     //50s are changed

    temp=coins/10;      //How many 10s can coins change
    printf("%d\n",temp);
    coins-=temp*10;

    temp=coins/5;
    printf("%d\n",temp);
    coins-=temp*5;

    printf("%d",coins);

    return 0;

}
