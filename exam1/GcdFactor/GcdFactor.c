#include<stdio.h>
int gcd(int,int);

int main(){
    int times;
    freopen("gcd_gcdfactor.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&times);
    while(times--){
        int a,b;
        scanf("%d%d",&a,&b);
        int min=a,max=a;
        if(min>b) min=b;
        if(max<b) max=b;
        int GCD=gcd(min,max),i,sum=0;
        for(i=1;i*i<=GCD;i++)
            if(GCD%i==0){
               sum+=i;
               if(GCD/i != i)
                sum+=GCD/i;
            }
        printf("%d %d\n",GCD,sum);
    }
    return 0;
}

int gcd(int a,int b){
    int x=1;
    while(a!=0 && b!=0){
       if(a>b) a%=b;
       else b%=a;
       if(!a) x=b;
       else x=a;
    }
    return x;
}
