#include<cstdio>
using namespace std;
void sol(int);
int dp(int,int,int*,int*);
int main(void){
    int n;
    while(scanf("%d",&n),n) sol(n);
    return 0;
}

void sol(int m){
    int n=1<<m;
    int *wei = new int[n];
    int *cost = new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&wei[i]);
        cost[i]=-1;
    }
    cost[0]=wei[0];
    int ans=dp(n-1,m,cost,wei);
    printf("%d\n",ans);
    delete wei,cost;
}

int dp(int a,int n,int *cost,int *wei){
    if(cost[a]>=0) return cost[a];
    int tmp=0;
    for(int i=0;i<n;i++)
        if(a & (1<<i)){
            int b=dp(a^(1<<i),n,cost,wei);
            if(b>tmp) tmp=b;
        }
    cost[a] = tmp + wei[a];
    return cost[a];
}
