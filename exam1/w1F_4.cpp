#include<iostream>
using namespace std;
void sol();
int judge(int);
int digit[10]={0};
int main(){
    int n;
    cin>>n;
    while(n--) sol();
    return 0;
}

void sol(){
    int n,i,counter=0;
    cin>>n;
    for(i=1;i<=n;i++) if(judge(i)) counter++;
    cout<<counter<<endl;
    return ;
}

int judge(int a){
    for(int i=0;i<10;i++) digit[i]=0;
    while(a){
        digit[a%10]++;
        a/=10;
    }
    for(int i=0;i<10;i++) if(digit[i]>1) return 0;
    return 1;
}
