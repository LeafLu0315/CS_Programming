#include<iostream>
using namespace std;
int Gcd(int,int);
void factor(int);
int main(){
    int n,Q1,Q2,R1,R2;
    cin>>n;
    while(n--){
        cin>>Q1>>R1>>Q2>>R2;
        factor(Gcd((Q1-R1),(Q2-R2)));
    }
    return 0;
}

int Gcd(int a, int b){
    if(!b) return a;
    return Gcd(b,a%b);
}

void factor(int a){
    for(int i=1;i<a;i++) if(!(a%i)) cout<<i<<" ";
    cout<<a;
    return;
}
