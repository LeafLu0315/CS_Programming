#include<bits/stdc++.h>
#define N 1000000
using namespace std;
int table[N],w[N];

int sol(int node,int n){
    if(table[node]>=0) return table[node];
    int M=0,m=0;
    for(int i=0;i<n;i++){
        if(node&(1<<i)) m=sol(node^(1<<i),n);
        if(M<m) M=m;
    }
    table[node]=M+w[node];
    return table[node];
}

int main(void){
    int n,ans,node,i;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        node=1;
        for(i=0;i<n;i++) node=node<<1;
        for(i=0;i<node;i++){
            scanf("%d",&w[i]);
            table[i]=-1;
        }
        ans=sol(node-1,n);
        printf("%d\n",ans);
    }
    return 0;
}
