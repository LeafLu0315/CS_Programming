#include<stdio.h>

int main(){
    int x,y,n;
//    freopen("array01.txt","r",stdin);
    while(1){
        scanf("%d%d%d",&x,&y,&n);
        if(!x*y*n) break;
        int temp=1;
        while(y--)
            temp*=x;
        printf("%d\n",temp%n);
    }
    return 0;
}
