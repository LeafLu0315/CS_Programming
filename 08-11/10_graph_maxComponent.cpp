#include<stdio.h>
#define MAX_NODES 50100
int parent[MAX_NODES];

int find(int n){
    while(parent[n]>=0) n=parent[n];
    return n;
}

int main(void){
    int ncase,node_nums,edge_nums,i,weight[MAX_NODES],r1,r2,u,v,ans;
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d%d",&node_nums,&edge_nums);
        for(i=0;i<node_nums;i++){
            scanf("%d",&weight[i]);
            parent[i]=-1;
        }
        for(i=0;i<edge_nums;i++){
            scanf("%d%d",&u,&v);
            r1=find(u);
            r2=find(v);
            if(r1!=r2){
                if(r1>r2) r1^=r2^=r1^=r2;
                weight[r1]+=weight[r2];
                parent[r1]+=parent[r2];
                parent[r2]=r1;
            }
        }
        ans=-1;
        for(i=0;i<node_nums;i++)
            if(parent[i]<0 && weight[i]>ans) ans=weight[i];
        printf("%d\n",ans);
    }
    return 0;
}
