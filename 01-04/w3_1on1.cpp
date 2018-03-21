#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int i,j,n,ene[10100],sold[10100],ans;
    while(scanf("%d",&n),n){
        ans=0;
        for(i=0;i<n;i++) scanf("%d",&ene[i]);
        for(i=0;i<n;i++) scanf("%d",&sold[i]);
        sort(sold,sold+n);
        sort(ene,ene+n);
        for(i=0,j=0;i<n;i++)
            if(sold[i]>ene[j]){
                ans++;
                j++;
            }
        printf("%d\n",ans);
    }
    return 0;
}
