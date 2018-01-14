#include<stdio.h>
int gcd(int,int);

int main(){
    int times;
    scanf("%d",&times);
    while(times--){

    }
}

int gcd(int a,int b){
    int GCD=1;
    while(a && b){
        if(a>b) a%=b;
        else    b%=a;
        if(!a) GCD=b;
        if(!b) GCD=a;
    }
    return GCD;
}
