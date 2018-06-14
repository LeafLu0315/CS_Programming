#include<bits/stdc++.h>
#define N 20001
using namespace std;
int f0[N],f1[N],w[N];
vector<int> child[N];

void dfs(int r){
    f0[r]=0;
    f1[r]=w[r];
    for(int c:child[r]){
        dfs(c);
        f0[r]+=max(f0[c],f1[c]);
        f1[r]+=f0[c];
    }
}

int main(void){
    int Tcase,parent,n;
    freopen("DP_indepTree.in","r",stdin);
    scanf("%d",&Tcase);
    while(Tcase--){
        scanf("%d%d",&n,&w[1]);
        for(int i=1;i<=n;i++) child[i].clear();
        for(int i=2;i<=n;i++){
            scanf("%d%d",&parent,&w[i]);
            child[parent].push_back(i);
        }
        dfs(1);
        printf("%d\n",max(f0[1],f1[1]));
    }
    return 0;
}
