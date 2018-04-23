/*6. 輸入一個整數，輸出它是否為平方數，
一個平方數是其他整數的平方 例如 36 , 49, 64, ...*/
#include<stdio.h>
int sol();
int main(){
    if(sol()) printf("Yes\n");
    else printf("No");
    return 0;
}

int sol(){
    int a,i;
    scanf("%d",&a);
    for(i=1;i*i<=a;i++)
        if(i*i == a) return 1;
    return 0;
}
