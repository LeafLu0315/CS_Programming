#include<iostream>
#include<algorithm>
#define N 1000
using namespace std;
void sol();
int main(){
    int times;
    cin>>times;
    while(times--) sol();
    return 0;
}

void sol(){
    int n,i,past,ans;
    int t[N];
    cin>>n;
    for(i=0;i<n;i++) cin>>t[i];
    sort(t,t+n);
    ans=past=t[0];
    for(i=1;i<n;i++) {past+=t[i]+t[i-1]; ans+=past;}
    cout<<ans<<endl;
    return;
}
