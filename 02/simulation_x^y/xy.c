#include<stdio.h>
void xyp();
int main(){
    int times;
    scanf("%d",&times);
    while(times--) xyp();
    return 0;
}

void xyp(){
    int p,res=1;
    long long x,y;
    scanf("%ld%ld%d",&x,&y,&p);
    do{
        if(y & 1){
            res*=x;
            res%=p;
        }
        x*=x;
        x%=p;
    }while(y>>=1);
    printf("%d\n",res);
    return;
}
