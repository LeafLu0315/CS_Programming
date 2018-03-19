#include<stdio.h>
int main(){
    unsigned long long x,y,p,xt;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&x,&y,&p);
        xt=1;
        while(y){
            if(y&1) xt=(x*xt)%p;
            y>>=1;
            x=(x*x)%p;
        }
        printf("%lld\n",xt);
    }
    return 0;
}
