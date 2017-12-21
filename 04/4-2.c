#include<stdio.h>

int main(){
    int x[3]={0},y[3]={0};
    int i;
    for(i=0;i<3;i++)
        scanf("%d%d",&x[i],&y[i]);
    int max=x[0]*x[0]+y[0]*y[0],a=x[0],b=y[0];
    for(i=0;i<3;i++){
        if(max<x[i]*x[i]+y[i]*y[i]){
            max=x[i]*x[i]+y[i]*y[i];
            a=x[i];
            b=y[i];
        }
    }
    printf("%d\n%d\n",a,b);
    return 0;
}

