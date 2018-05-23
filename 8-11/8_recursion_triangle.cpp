#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N,a[35];
    while(cin>>N){
        if(!N) break;
        for(int i=0;i<N;i++) cin>>a[i];
        sort(a,a+N);
        int ans = 0;
        for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) for(int k=j+1;k<N;k++)
            if(a[k]<a[i]+a[j]) ans++;
        cout<<ans<<"\n";
    }
    return 0;
}
