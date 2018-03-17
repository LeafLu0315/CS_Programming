#include<stdio.h>
int gcd(int,int);
void factors(int);
int main(){
    int times,Q1,Q2,R1,R2;
    scanf("%d",&times);
    while(times--){
        scanf("%d%d%d%d",&Q1,&R1,&Q2,&R2);
        factors(gcd(Q1-R1,Q2-R2));
    }
    return 0;
}

int gcd(int a, int b){
    if(!b) return a;
    return gcd(b,a%b);
}

void factors(int a){
    int i;
    for(i=1;i<a;i++) if(!(a%i)) printf("%d ",i);
    printf("%d\n",i);
    return ;
}
