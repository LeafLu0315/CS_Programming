#include<iostream>
#include<cstdio>
#define N 300
using namespace std;
void sol(int);
void init(int);
long long road[N][N],dp[N][N];
int main(void){
    int n;
    while(scanf("%d",&n),n) sol(n);
    return 0;
}

void sol(int n){
    int m = n+1;
    init(m);
    for(int i=1;i<m;i++) for(int j=1;j<m;j++) scanf("%lld",&road[i][j]);
    for(int i=1;i<m;i++) for(int j=1;j<m;j++) dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + road[i][j];
    printf("%lld\n",dp[n][n]);
}

void init(int m){
    for(int i=0;i<m;i++) for(int j=0;j<m;j++) dp[i][j]=road[i][j]=0;
}
