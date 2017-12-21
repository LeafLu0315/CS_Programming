#include<stdio.h>

int main(){
    int a=4,i,c=1;
    while(a!=1){
        for(i=2;i<=a;i++){
            if(a%i==0){
                printf("a=%d i=%d c=%d\n",a,i,c);
                c++;
                a/=i;
                continue;
            }
        }
    }
}
