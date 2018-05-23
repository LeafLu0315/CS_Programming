#include<bits/stdc++.h>
#define N 10000
using namespace std;

int main(void){
    int ncase,spies,t[N]={0},i;
    scanf("%d",&ncase);
    while(ncase--){
        int monitored[N]={0},sum=0;
        scanf("%d",&spies);
        for(i=1;i<spies;i++) scanf("%d",&t[i]);
        for(i=spies-1;i>=0;i--){
            if(!monitored[i]) monitored[t[i]]=1;
            else sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
