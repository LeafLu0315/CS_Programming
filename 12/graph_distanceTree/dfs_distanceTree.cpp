#include<cstdio>
#include<vector>
#include<queue>
#define N 5001
using namespace std;
void sol();
void dfs(int);

int parent[N],edge[N],node[N],nodes,ans;
vector<int> child[N];
int main(void){
    int n;
    scanf("%d",&n);
    while(n--) sol();
    return 0;
}

void sol(){
    queue<int> q;
    scanf("%d",&nodes);
    for(int i=1;i<=nodes;i++){
        child[i].clear();
        node[i]=1;
    }
    for(int i=2;i<=nodes;i++) scanf("%d",&parent[i]);
    for(int i=2;i<=nodes;i++){
        scanf("%d",&edge[i]);
        child[parent[i]].push_back(i);
    }
    ans=0;
    dfs(1);
    printf("%d\n",ans);
}

void dfs(int n){
    for(int a : child[n]){
        dfs(a);
        node[n]+=node[a];
        ans+=2*node[a]*(nodes-node[a])*edge[a];
    }
}
