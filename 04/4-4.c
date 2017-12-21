#include<stdio.h>

int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int length=a-c,width=b-d;
    if(a-c < 0)
        length=c-a;
    if(b-d < 0)
        width=d-b;
    printf("%d\n",2*(length+width));
    return 0;
}
