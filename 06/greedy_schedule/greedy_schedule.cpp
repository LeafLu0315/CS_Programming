#include<iostream>
#define N 3000
using namespace std;
void sol();
int t[N];
int main(){
    int n;
    cin>>n;
    while(n--) sol();
    return 0;
}

void sol(){
    int time,machine,T,i,j,k;
    cin>>time>>machine;
    for(i=0;i<machine;i++) t[i]=0;
    for(i=0;i<time;i++){
        cin>>T;
        for(j=0,k=1;k<machine;k++) if(t[k]<t[j]) j=k;
        t[j]+=T;
    }
    for(i=0,j=0;i<machine;i++) if(t[i]>t[j]) j=i;
    cout<<t[j]<<endl;
    return ;
}
