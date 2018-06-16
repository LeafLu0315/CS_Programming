#include<bits/stdc++.h>
#define N 1000
#define M 200000
using namespace std;

int main(void){
    int ncase,wnum,onum,weight[N],object[N],total,counting,k;
    bool a[M];
    cin>>ncase;
    while(ncase--){
        cin>>wnum>>onum;
        for(int i=0;i<wnum;i++) cin>>weight[i];
        for(int i=0;i<onum;i++) cin>>object[i];
        total=0;
        memset(a,0,sizeof(a));
        a[0]=1;
        for(int i=0;i<wnum;i++){
            k=weight[i];
            for(int j=total;j>=0;j--) if(a[j]) a[j+k]=1;
            total+=k;
        }
        counting=0;
        for(int i=0;i<onum;i++) if(a[object[i]]) counting++;
        cout<<counting<<endl;
    }
    return 0;
}
