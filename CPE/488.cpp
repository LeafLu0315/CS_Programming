#include<iostream>
using namespace std;
int main(void){
    int ncase,times,maximum;
    bool b = true;
    cin>>ncase;
    while(ncase--){
        cin>>maximum>>times;
        while(times--){
            if(b) b = false;
            else cout<<"\n";
            for(int i=1;i<=maximum;i++){
                for(int j=1;j<=i;j++) cout<<i;
                cout<<"\n";
            }
            for(int i=maximum-1;i>0;i--){
                for(int j=1;j<=i;j++) cout<<i;
                cout<<"\n";
            }
        }
    }
    return 0;
}
