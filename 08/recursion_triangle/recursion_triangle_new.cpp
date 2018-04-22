#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 10000
using namespace std;
void sol(int);
int leng[N];
int main(){
    int n;
    while(scanf("%d",&n),n) sol(n);
    return 0;
}

void sol(int n){
    int i,j,k,ans=0;
    for(i=0;i<n;i++) scanf("%d",leng+i);
    sort(leng,leng+n);
    for(i=0;i<n;i++) for(j=i+1;j<n;j++) for(k=j+1;k<n;k++)
        if(leng[i]+leng[j]>leng[k]) ans++;
    cout<<ans<<endl;
    return;
}
