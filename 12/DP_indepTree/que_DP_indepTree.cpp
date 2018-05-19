#include<cstdio>
#include<queue>
using namespace std;
void sol(int);
int main(){
    int ncase,n;
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d",&n);
        sol(n);
    }
    return 0;
}

void sol(int n){
    queue<int> q;
    int pick[n+1],notpick[n+1],parent[n+1],degree[n+1];
    for(int i=1;i<=n;i++) pick[i]=notpick[i]=parent[i]=degree[i]=0;
    scanf("%d",&pick[1]);
    for(int i=2;i<=n;i++){
        scanf("%d%d",&parent[i],&pick[i]);
        degree[parent[i]]++;
    }
    for(int i=2;i<=n;i++) if(!degree[i]) q.push(i);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        notpick[parent[f]] += max(pick[f],notpick[f]);
        pick[parent[f]] += notpick[f];
        degree[parent[f]]--;
        if(!degree[parent[f]]) q.push(parent[f]);
    }
    printf("%d\n",max(pick[1],notpick[1]));
}
