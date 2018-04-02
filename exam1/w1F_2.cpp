#include<iostream>
using namespace std;
void sol();
int judge(int);
int digit[7]={0};
int main(){
    int n;
    cin>>n;
    while(n--) sol();
    return 0;
}

void sol(){
    int n,c=0;
    cin>>n;
    for(int i=1;i<=n;i++) if(judge(i)) c++;
    cout<<c<<endl;
    return ;
}

int judge(int a){
    int counter=0;
    while(a){
        digit[counter++]=a%10;
        a/=10;
    }
    for(int i=0;i<counter-1;i++) if(digit[i]>digit[i+1]) return 0;
    return 1;
}
