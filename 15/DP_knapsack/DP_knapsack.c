#include<stdio.h>
#define N 25
void dfs(int,int,int,int);
void sol();
int n,l,wa,wb,z,bestv,bestw;
int w[N],v[N];
int main(void){
    int ending=0;
    while(!ending){
        sol();
        scanf("%d",&ending);
    }
    return 0;
}
void sol(){
    scanf("%d%d%d%d",&n,&l,&wa,&wb);
    for(int i=0;i<n;i++) scanf("%d%d",&v[i],&w[i]);
    z=-1;
    dfs(0,0,0,0);
    printf("%d\n",z);
}

void dfs(int dep,int c,int sv,int sw){
    if(sw>wb) return;
    int t;
    if(dep==n){
        if(c>=l&&sw>=wa){
            t=sv/sw;
            if(t*sw!=sv)++t;
            if(t>z)z=t;
        }
        return;
    }
    dfs(dep+1,c+1,sv+v[dep],sw+w[dep]);
    dfs(dep+1,c,sv,sw);
}
