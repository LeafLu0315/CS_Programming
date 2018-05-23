#include<stdio.h>
#include<vector>
#define N 100001
using namespace std;
int st[101],v[5001],visited[5001],ans;
void traversal(int s,vector<int> edge[]){
    int y;
    if(visited[s]==1) return;
    visited[s]=1;
    if(v[s]>ans) ans=v[s];
    while(!edge[s].empty()){
        y=edge[s].back();
        traversal(y,edge);
        edge[s].pop_back();
    }
}

int main(void){
    int n,m,t;
    while(1){
        scanf("%d%d%d",&n,&m,&t);
        if(n==0&&m==0&&t==0) break;
        ans=0;
        int i,x,y;
        for(i=0;i<t;i++) scanf("%d",&st[i]);
        for(i=0;i<n;i++) scanf("%d",&v[i]);
        vector<int> edge[N];
        for(i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            edge[x].push_back(y);
        }
        int s;
        for(i=0;i<n;i++) visited[i]=0;
        for(i=0;i<t;i++){
            s=st[i];
            traversal(s,edge);
        }
        printf("%d\n",ans);
    }
    return 0;
}
