#include<stdio.h>

int gcd(int Q1,int Q2){
    if(Q1%Q2!=0){
        Q1%=Q2;
        Q2=gcd(Q2,Q1);
    }
    return Q2;
}

int main(void){
    int d,i,Q1,Q2,R1,R2,ncase;
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d%d%d%d",&Q1,&R1,&Q2,&R2);
        Q1-=R1;Q2-=R2;
        d=gcd(Q1,Q2);
        printf("1");
        for(i=2;i<=d;i++) if(d%i==0) printf(" %d",i);
        if(ncase) printf("\n");
    }
    return 0;
}
