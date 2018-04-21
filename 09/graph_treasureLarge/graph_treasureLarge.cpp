#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#define N 50000
#define M 100000
using namespace std;
void sol(int,int,int);
int main(void){
    int cities,road,starting;
    while(cin>>cities>>road>>starting,cities) sol(cities,road,starting);
    return 0;
}

void sol(int cities,int road,int starting){
    vector<int> edge[M];
    queue<int> q;
    int start[N],val[N],i,u,v,ans=0;
    bool visit[N];
    for(i=0;i<starting;i++) scanf("%d",&start[i]);
    for(i=0;i<cities;i++){
        scanf("%d",&val[i]);
        visit[i]=false;
    }
    for(i=0;i<road;i++){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
    }
    for(i=0;i<starting;i++){
        int k=start[i];
        if(visit[k]) continue;
        visit[k]=true;
        q.push(k);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(val[x]>ans)ans=val[x];
            for(int y:edge[x])
                if(!visit[y]){
                    q.push(y);
                    visit[y]=true;
                }
        }
    }
    cout<<ans<<endl;
    return ;
}
