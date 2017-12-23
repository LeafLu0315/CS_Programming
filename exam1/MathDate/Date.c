#include<stdio.h>

int main(){
    int y,m,d,times;
    freopen("math_date.in","r",stdin);
    scanf("%d",&times);
    while(times--){
        int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        scanf("%d/%d/%d",&y,&m,&d);
        if(y%400==0 || (y%4==0 && y%100!=0)) month[1]=29;
        if(d<=0 || d>month[m-1] || m<1 || m>12 || y<2000) printf("No\n");
        else printf("Yes\n");
    }
    return 0;

}
