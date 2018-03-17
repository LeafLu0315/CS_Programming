#include<iostream>
using namespace std;
void xyp();
int main(){
    int times;
    cin>>times;
    while(times--) xyp();
    return 0;
}

void xyp(){
    int p,res=1;
    long long x,y;
    cin>>x>>y>>p;
    do{
        if(y & 1){
            res*=x;
            res%=p;
        }
        x*=x;
        x%=p;
    }while(y>>=1);
    cout<<res<<endl;
    return;
}

