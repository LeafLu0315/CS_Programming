#include<stdio.h>
#include<string.h>

int g[20],max;

void solve(int d,int good){
    int i;
    if(!good){
        if(d>max) max=d;
        return ;
    }
    while(good){
        i=__builtin_ctz(good);
        solve(d+1,good & g[i]);
        good &= ~(1<<i);
    }
}

int main(){
    int i,j,n,tmp;
    freopen("clique.in","r",stdin);
    while(scanf("%d",&n),n){
        memset(g,0,sizeof(g));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                scanf("%d",&tmp);
                if(tmp) g[i] |=(1<<j);
            }
        max=0;
        solve(0,(1<<n)-1);
        printf("%d\n",max);
    }
    return 0;
}
