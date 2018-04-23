/*4. 輸入三個整數，輸出最大、最小的數*/
#include<stdio.h>
void sol();
int main(){
    sol();
    return 0;
}
void sol(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int max=a,min=a;
    if(b>max) max=b;
    if(c>max) max=c;
    if(b<min) min=b;
    if(c<min) min=c;
    printf("%d %d\n",max,min);
    return ;
}
