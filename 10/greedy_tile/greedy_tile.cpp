#include<cstdio>
#include<algorithm>
#define N 12000
struct TILE{
    int length,width;
};
void sol();
bool cmp(TILE,TILE);
int main(){
    int n;
    scanf("%d",&n);
    while(n--) sol();
    return 0;
}

void sol(){
    int n,i;
    TILE t[N];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d %d",&t[i].length,&t[i].width);
    for(int i=0;i<n;i++){
        t[n+i].length = t[i].width;
        t[n+i].width = t[i].length;
    }
    std::sort(t,t+2*n,cmp);
    int height=t[0].length,wid=t[0].width;
    for(int i=1;i<n*2;i++){
        if(t[i].width == wid) continue;
        height += t[i].length;
        wid = t[i].width;
    }
    printf("%d\n",height);
    return ;
}

bool cmp(TILE a,TILE b){
    if(a.width == b.width) return a.length > b.length;
    return a.width > b.width;
}
