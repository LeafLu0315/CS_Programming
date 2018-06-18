#include<bits/stdc++.h>
using namespace std;
struct Item{
    int w,v;
};
int N,L,Wa,Wb,max_avg_value=-1;
Item items[20];
void dfs(int i,int total_v,int total_w,int cnt){
    if(total_w>Wb) return;
    if(i==N-1){
        if(cnt>=L && Wa<=total_w && total_w<=Wb){
            int avg = total_v/total_w + ((total_v%total_w)==0 ? 0:1);
            max_avg_value = max(max_avg_value,avg);
        }
        return;
    }
    dfs(i+1,total_v+items[i+1].v,total_w+items[i+1].w,cnt+1);
    dfs(i+1,total_v,total_w,cnt);
}
int main(void){
    while(scanf("%d%d%d%d",&N,&L,&Wa,&Wb)){
        for(int i=0;i<N;i++) scanf("%d%d",&items[i].v,&items[i].w);
        dfs(0,items[0].v,items[0].w,1);
        dfs(0,0,0,0);
        printf("%d\n",max_avg_value);
        int flag;
        scanf("%d",&flag);
        if(flag==-1) break;
        max_avg_value=-1;
    }
    return 0;
}

