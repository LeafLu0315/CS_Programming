#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int A=a*a,B=b*b,C=c*c;
    if(A+B==C || B+C==A ||A+C==B)
        printf("3");
    else
    {
        float cos[3]={0}; //initialize
        cos[0]=(float)(A+B-C)/(2*a*b);
        cos[1]=(float)(B+C-A)/(2*b*c);
        cos[2]=(float)(A+C-B)/(2*a*c);
        if(cos[0]>0&&cos[1]>0&&cos[2]>0)
            printf("1");
        else
            printf("2");
    }
    return 0;

}
