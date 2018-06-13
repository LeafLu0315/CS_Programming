#include<bits/stdc++.h>
using namespace std;

void sol(int n){
    long long graph[n+1][n+1];
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) graph[i][j]=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&graph[i][j]);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) graph[i][j]+=max(graph[i-1][j],graph[i][j-1]);
    printf("%lld\n",graph[n][n]);
    return;
}

int main(void){
    int n;
    freopen("DP_jewel.in","r",stdin);
    while(scanf("%d",&n),n) sol(n);
    return 0;
}
