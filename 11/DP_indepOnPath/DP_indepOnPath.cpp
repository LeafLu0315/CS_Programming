#include<iostream>
#include<cstdio>
using namespace std;
void sol(int);
int main(void){
    int n;
    while(scanf("%d",&n),n) sol(n);
    return 0;
}

void sol(int n){
    int max1=0,max2=0;
    for(int i=0;i<n;i++){
        int a,tmp,tmp2;
        scanf("%d",&a);
        tmp = max2 + a;
        tmp2= max(max1,max2);
        max1=tmp; max2=tmp2;
    }
    printf("%d\n",max(max1,max2));
}
