#include<stdio.h>
int Gcd(int,int);
int main(){
    int times,a,b,gcd,count;
    scanf("%d",&times);
    while(times--){
        scanf("%d%d",&a,&b);
        printf("gcd(%d,%d)=",a,b);
        gcd=1;
        if(b>a) count=1;
        else count=0;
        while(a && b){
            if(a>b)
                a%=b;
            else
                b%=a;
            count++;
            if(a) gcd=a;
            else if(b) gcd=b;
        }
        printf("%d, using %d division.\n",gcd,count);
    }
    return 0;
}
