#include<cstdio>
#include<vector>
#include<queue>
#define N 5001
using namespace std;
void sol();

int main(void){
    int n;
    scanf("%d",&n);
    while(n--) sol();
    return 0;
}

void sol(){
    int ans=0,i,nodes;
    int parent[N],edge[N],node[N],degree[N];
    queue<int> q;
    scanf("%d",&nodes);
    for(i=2;i<=nodes;i++) scanf("%d",&parent[i]);
    for(i=2;i<=nodes;i++) scanf("%d",&edge[i]);
    for(i=1;i<=nodes;i++){
        degree[i]=0;
        node[i]=1;
    }
    for(i=2;i<=nodes;i++) degree[parent[i]]++;
    for(i=1;i<=nodes;i++) if(!degree[i]) q.push(i);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        node[parent[f]]+=node[f];
        ans += 2*node[f]*(nodes-node[f])*edge[f];
        degree[parent[f]]--;
        if(!degree[parent[f]]) q.push(parent[f]);
    }
    printf("%d\n",ans);
}
