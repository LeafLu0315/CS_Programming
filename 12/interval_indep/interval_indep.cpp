#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct LINE{
    int left,right,weight;
};
void sol(int);
bool cmp(LINE,LINE);
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
    LINE *line = (LINE*) malloc(sizeof(LINE)*(n+1));
    int *dp = (int*) malloc(sizeof(int)*(n+1));
    fill(dp,dp+sizeof(dp),0);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&line[i].left,&line[i].right,&line[i].weight);
    sort(line+1,line+n+1,cmp);
    line[0].right=0;
    for(int i=1;i<=n;i++){
        int l=0,r=i-1,x;
        while(r-l>1){
            x=(r+l)/2;
            if(line[x].right<=line[i].left) l=x;
            else r=x-1;
        }
        x=(line[r].right<=line[i].left) ? r:l;
        dp[i]=max(dp[i-1],dp[x]+line[i].weight);
    }
    printf("%d\n",dp[n]);
}

bool cmp(LINE a,LINE b){
    return a.right<b.right;
}
