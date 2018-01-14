#include<stdio.h>
int xyp(long long int,int,int);
int main(){
    int x,y,p;
    freopen("bitOperator_xypLog.in","r",stdin);
    freopen("o.txt","w",stdout);
    while(1){
        scanf("%d",&x);
        if(!x) break;
        scanf("%d%d",&y,&p);
        printf("%d\n",xyp(x,y,p));
    }
    return 0;
}

int xyp(long long int x,int y,int p){
    long long int res=1;
    while(y){
        if(y&1) res*=x;
        x*=x;
        x%=p;
        res%=p;
        y>>=1;
    }
    return (int)res;
}
