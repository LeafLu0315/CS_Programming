#include<iostream>
using namespace std;
typedef long long LL;
LL xnp(LL,LL,LL);
int main(){
    char n[210],x[210];
    LL tmp,tmp2,p;
    int i;
    while(cin>>x>>n>>p){
        tmp=tmp2=0;
        for(i=0;x[i];i++) tmp=(tmp*10+x[i]-'0')%p;
        for(i=0;n[i];i++) tmp2=(tmp2*10+n[i]-'0')%(p-1);
        cout<<xnp(tmp,tmp2,p)<<endl;
    }
    return 0;
}

LL xnp(LL x,LL y,LL p){
    LL res=1;
    while(y){
        if(y&1) res=(res*x)%p;
        x=(x*x)%p;
        y>>=1;
    }
    return res;
}
