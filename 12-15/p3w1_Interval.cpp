#include<bits/stdc++.h>
#define N 100010
using namespace std;
struct SEG{
    int l,r,w;
};
SEG seg[N];
bool cmp(SEG p,SEG q){
    return p.r<q.r;
}

bool check(int mid,int i){
    return seg[mid].r<=seg[i].l;
}

int main(void){
    int i,j,k,t,n,r,l,mid;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d%d%d",&seg[i].l,&seg[i].r,&seg[i].w);
        sort(seg+1,seg+n+1,cmp);
        int dp[N]={0};
        for(i=1;i<=n;i++){
            l=k=0;
            r=i;
            while(r-l>1){
                mid=(l+r)/2;
                if(check(mid,i)) l=mid;
                else r=mid;
            }
            dp[i]=dp[l]+seg[i].w;
            dp[i]=max(dp[i-1],dp[i]);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
