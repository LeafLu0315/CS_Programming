#include<bits/stdc++.h>
#define N 100
#define M 55
using namespace std;
int point[N],dp[M][M];

int cut(int l,int r){
    if(r-l==1) return dp[l][r]=0;
    if(dp[l][r]!=-1) return dp[l][r];
    int m = 0x3f3f3f3f;
    for(int i=l+1;i<r;i++) m=min(m,cut(l,i)+cut(i,r)+point[r]-point[l]);
    return dp[l][r]=m;
}

int main(void){
    int len,i,n;
    freopen("DP_hypercube.in","r",stdin);
    while(scanf("%d",&len)!=EOF){
        if(!len) break;
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        point[0]=0;
        for(i=1;i<=n;i++) scanf("%d",&point[i]);
        point[i]=len;
        printf("The minimum cutting is %d.\n",cut(0,n+1));
    }
    return 0;
}
