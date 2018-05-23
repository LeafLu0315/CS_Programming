#include<bits/stdc++.h>
using namespace std;
int trea[5100];
vector<int> road[5100];
bool flag[5100];
int ans;
void dfs(int v){
    int i;
    flag[v]=true;
    if(trea[v]>ans) ans = trea[v];
    for(i=0;i<road[v].size();i++)
        if(flag[road[v][i]]==false)
            dfs(road[v][i]);
}

int main(void){
    int n1,n2,stanum,roadnum,cit,i,start[150];
    while(1){
        memset(trea,0,sizeof(trea));
        memset(flag,false,sizeof(flag));
        ans=0;
        cin>>cit>>roadnum>>stanum;
        if(cit==0) break;
        for(i=0;i<stanum;i++) cin>>start[i];
        for(i=0;i<cit;i++) cin>>trea[i];
        for(i=0;i<roadnum;i++){
            cin>>n1>>n2;
            road[n1].push_back(n2);
        }
        for(i=0;i<stanum;i++) dfs(start[i]);
        cout<<ans<<endl;
        for(i=0;i<5100;i++) road[i].clear();
    }
    return 0;
}
