/*
輸入一個等差級數的首位數，差值，與 k, 輸出第 k 位數。
例如，輸入 10 3 5 則輸出 22
*/
#include<stdio.h>
void sol();
int main(){
    sol();
    return 0;
}

void sol(){
    int first,substract,k;
    scanf("%d%d%d",&first,&substract,&k);
    printf("%d",first+substract*(k-1));
    return ;
}
