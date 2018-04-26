#include<cstdio>
#include<vector>
#include<queue>
#define N 50000
#define M 1000000
using namespace std;

int start[N],wei[N];
vector<int> edge[N];
bool visit[N];
void sol();
int bfs(int);

int main(){
    int n;
    scanf("%d",&n);
    while(n--) sol();
    return 0;
}

void sol(){
    int n,m,u,v,i,ans=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",wei+i);
        visit[i] = false;
        edge[i].clear();
    }
    for(i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(i=0;i<n;i++){
        if(visit[i]) continue;
        int k=bfs(i);
        if(k>ans) ans=k;
    }
    printf("%d\n",ans);
    return;
}

int bfs(int a){
   queue<int> q;
   int t=wei[a];
   q.push(a);
   visit[a]=true;
   while(!q.empty()){
        int f=q.front();
        q.pop();
        for(int v : edge[f]){
            if(visit[v]) continue;
            q.push(v);
            visit[v]=true;
            t+=wei[v];
        }
   }
   return t;
}
