#include<stdio.h>
int powerfunc(int,int);

int main(){
    int x,y,n;
    while(1){
        scanf("%d%d%d",&x,&y,&n);
        if(!x && !y && !n)
            break;
        int result=powerfunc(x,y)%n;
        printf("%d\n",result);
    }
    return 0;
}

int powerfunc(int x,int y){
    int i,result=1;
    for(i=1;i<=y;i++)
        result*=x;
    return result;
}
