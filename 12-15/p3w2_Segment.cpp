#include<iostream>
using namespace std;

int main(void){
    int ncase,n;
    cin>>ncase;
    while(--ncase>=0){
        cin>>n;
        int ans=0,t,tmp=0;
        cin>>tmp;
        for(int i=1;i<n;i++){
            cin>>t;
            if(tmp>0){
                ans = (tmp+t>ans)?tmp+t:ans;
                tmp+=t;
            }
            else tmp=t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
