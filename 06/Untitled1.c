#include<stdio.h>
int main(){
    int x,y,n;
//    freopen("input.txt","r",stdin);
    while(1){
        scanf("%d",&x);
        if(!x) break;
        scanf("%d%d",&y,&n);
        int k=1;
        while(y--){
                k*=x%n;
                k%=n;
        }
        printf("%d\n",k%n);
    }
    return 0;
}
