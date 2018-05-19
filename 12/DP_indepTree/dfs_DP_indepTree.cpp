#include<cstdio>
#include<vector>
#define N 1001
using namespace std;
void sol();
void dfs(int);
vector<int> child[N];
int R[N],pick[N],notpick[N];

int main(){
    int n;
    scanf("%d",&n);
    while(n--) sol();
    return 0;
}

void sol(){
    int n,parent;
    scanf("%d%d",&n,&R[1]);
    for(int i=1;i<=n;i++) child[i].clear();
    for(int i=2;i<=n;i++){
        scanf("%d%d",&parent,&R[i]);
        child[parent].push_back(i);
    }
    dfs(1);
    printf("%d\n",max(pick[1],notpick[1]));
}

void dfs(int r){
    pick[r]=0;
    notpick[r] = R[r];
    for(int c:child[r]){
        dfs(c);
        pick[r] += max(pick[c],notpick[c]);
        notpick[r] += pick[c];
    }
}
