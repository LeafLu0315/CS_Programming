#include<bits/stdc++.h>
using namespace std;
int main(void){
    int ncase;
    scanf("%d",&ncase);
    while(ncase--){
        int nkind;
        scanf("%d",&nkind);
        int h[501];
        memset(h,0,sizeof(h));
        for(int i=0;i<nkind;i++){
            int d1,d2;
            scanf("%d%d",&d1,&d2);
            if(d1>h[d2]) h[d2]=d1;
            if(d2>h[d1]) h[d1]=d2;
        }
        int ans=0;
        for(int i=0;i<=500;i++) ans+=h[i];
        printf("%d\n",ans);
    }
    return 0;
}
