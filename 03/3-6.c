#include<stdio.h>
int main()
{
    int a,b,c,d,k,h; //(a,b) (c,d) y=kx+h
    scanf("%d%d%d%d",&a,&b,&c,&d);
    k=(b-d)/(a-c);
    h=b-k*a;
    if(h==0)
        printf("%d",1);
    else
        printf("%d",0);
}
