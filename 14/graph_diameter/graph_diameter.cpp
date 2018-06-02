#include<cstdio>
#include<vector>
#include<queue>
#define N 100010
using namespace std;
void sol();
void bfs(int,int*,int,vector<int>*);
int main(void){
    int n;
    scanf("%d",&n);
    while(n--){
        sol();
        if(n) printf("\n");
    }
    return 0;
}

void sol(){
    int n;
    scanf("%d",&n);
    int *dis = new int[n];
    vector<int> *v = new vector<int>[n];
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(0,dis,n,v);
    int far=0,ans=0;
    for(int i=1;i<n;i++) if(dis[i]>dis[far]) far=i;
    bfs(far,dis,n,v);
    for(int i=0;i<n;i++) ans=max(ans,dis[i]);
    printf("%d",ans);
    delete [] dis,v;
}

void bfs(int a,int *dis,int n,vector<int> *v){
    queue<int> q;
    bool *visit = new bool[n];
    fill(visit,visit+n,false);
    fill(dis,dis+n,0);
    visit[a]=true;
    q.push(a);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(int u:v[f]){
            if(visit[u]) continue;
            visit[u]=true;
            dis[u]=dis[f]+1;
            q.push(u);
        }
    }
    delete visit;
}
