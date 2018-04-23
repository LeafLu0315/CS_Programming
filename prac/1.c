/*輸入一個年份，輸出它是否為閏年*/
#include<stdio.h>
void sol();
int main(){
    sol();
    return 0;
}

void sol(){
    int year;
    scanf("%d",&year);
    if((year%400 == 0) || (year%4 == 0 && year%100 !=0)) printf("Yes\n");
    else printf("No\n");
    return ;
}
