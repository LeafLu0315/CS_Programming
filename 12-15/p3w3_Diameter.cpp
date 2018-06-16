#include<bits/stdc++.h>
#define N 101000
using namespace std;

int bfs(vector<int> adj[],int n,int start){
    int dep[N],ans,pla,i;
    bool visit[N];
    memset(visit,false,sizeof(visit));
    memset(dep,0,sizeof(dep));
    ans = 0;
    queue<int> q;
    if(start==-1) q.push(0);
    else q.push(start);
    while(q.size()){
        int f=q.front();
        if(!visit[f]){
            visit[f]=true;
            for(i=0;i<adj[f].size();i++){
                dep[adj[f][i]]=dep[f]+1;
                if(dep[adj[f][i]]>ans){
                    ans=dep[adj[f][i]];
                    pla=adj[f][i];
                }
                q.push(adj[f][i]);
            }
        }
        q.pop();
    }
    if(start==-1) return pla;
    return ans;
}

int main(void){
    int t,n,i;
    scanf("%d",&t);
    while(t--){
        vector<int> adj[N];
        scanf("%d",&n);
        for(i=0;i<n-1;i++){
            int in1,in2;
            scanf("%d%d",&in1,&in2);
            adj[in1].push_back(in2);
            adj[in2].push_back(in1);
        }
        int top=bfs(adj,n,-1);
        printf("%d\n",bfs(adj,n,top));
    }
    return 0;
}
