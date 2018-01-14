#include<stdio.h>
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int perimeter=0,area=0;
    if(a<c&&b<d){
        perimeter=(c-a+d-b)*2;
        area=(c-a)*(d-b);
        printf("Perimeter=%d\nArea=%d",perimeter,area);
    }
    else if(a>c)
        printf("a>c");
    else
        printf("b>d");
    return 0;

}
