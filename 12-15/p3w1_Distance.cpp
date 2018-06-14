#include<bits/stdc++.h>
#define N 10002
#define INF 9999999
using namespace std;
int parent[N],edge[N],n_node[N],deg[N];

void sol(){
    int i,n;
    long long total=0;
    queue<int> q;
    scanf("%d",&n);
    for(i=2;i<=n;i++) scanf("%d",&parent[i]);
    for(i=2;i<=n;i++) scanf("%d",&edge[i]);
    for(i=1;i<=n;i++) deg[i]=0;
    for(i=2;i<=n;i++) deg[parent[i]]++;
    for(i=1;i<=n;i++) if(deg[i]==0) q.push(i);
    for(i=1;i<=n;i++) n_node[i]=1;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        n_node[parent[s]]+=n_node[s];
        total+=2*n_node[s]*(n-n_node[s])*edge[s];
        deg[parent[s]]--;
        if(deg[parent[s]]==0) q.push(parent[s]);
    }
    printf("%lld\n",total);
}

int main(void){
    int n;
    scanf("%d",&n);
    while(n--) sol();
    return 0;
}
