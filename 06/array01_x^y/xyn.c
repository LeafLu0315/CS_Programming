#include<stdio.h>
int main(){
    int x,y,n,result;
    while(1){
        scanf("%d",&x);
        if(!x) break;
        scanf("%d%d",&y,&n);
        result=1;
        while(y--){
            result*=(x%n);
            result%=n;
        }
        printf("%d\n",result);
    }
    return 0;
}
