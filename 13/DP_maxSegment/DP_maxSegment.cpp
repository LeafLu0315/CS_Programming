#include<cstdio>
#include<cstdlib>
void sol(int);
void init(int*,int);
int main(void){
    int ncase,n;
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d",&n);
        sol(n);
    }
    return 0;
}

void sol(int n){
    int m = n + 1,ans=0;
    int *num = (int*) malloc(sizeof(int)*m);
    int *dp = (int*) malloc(sizeof(int)*m);
    init(num,m);
    init(dp,m);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    for(int i=1;i<m;i++){
        dp[i] = (dp[i-1]>num[i-1]) ? dp[i-1]+num[i] : num[i-1]+num[i];
        if(dp[i] > ans) ans = dp[i];
    }
    printf("%d\n",ans);
}

void init(int *arr,int n){
    for(int i=0;i<n;i++) arr[i]=0;
}
