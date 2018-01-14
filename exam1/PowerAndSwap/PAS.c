#include<stdio.h>

int main(){
    int x,y,n;
    freopen("power_b.in","r",stdin);
    freopen("output.txt","w",stdout);
    while(1){
        scanf("%d",&x);
        if(!x) break;
        scanf("%d%d",&y,&n);
        int max=(x>y)? x:y,min=(x<y)? x:y,temp=1;
        while(min--){
            temp*=max%n;
            temp%=n;
        }
        printf("%d\n",temp);
    }
}
