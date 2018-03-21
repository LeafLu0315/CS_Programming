#include<stdio.h>
#define SZE 1000
typedef long long LL;
LL xyp(LL,LL,LL);
int main(){
    LL m,y,i,j,k,p;
    char x[SZE],n[SZE];
    while(scanf("%s%s%lld",x,n,&p)!=EOF){
        y=m=0;
        for(i=0;x[i];i++) y=(y*10+x[i]-'0')%p;
        for(i=0;n[i];i++) m=(m*10+n[i]-'0')%(p-1);
        printf("%lld\n",xyp(y,m,p));
    }
    return 0;
}

LL xyp(LL y,LL m,LL p){
    int i;
    LL t=1,xi,t2=y;
    while(m){
        if(m & 1) t=(t*t2)%p;
        m>>=1;
        t2=(t2*t2)%p;
    }
    return t;
}

