#include<cstdio>
#include<algorithm>
#define N 200000
using namespace std;
void sol();
bool able[N];
int main(void){
    int n;
    scanf("%d",&n);
    while(n--){
        sol();
        if(n) printf("\n");
    }
    return 0;
}

void sol(){
    int n,m,a,ans=0;
    scanf("%d%d",&n,&m);    //fama,item
    fill(able,able+N,false);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        for(int j=N;j>=0;--j) if(able[j]) able[j+a]=true;
        able[a]=true;
    }
    for(int i=0;i<m;++i){
        scanf("%d",&a);
        if(able[a]) ++ans;
    }
    printf("%d",ans);
}
