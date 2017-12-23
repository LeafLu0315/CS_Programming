#include<stdio.h>
int main(){
    int times;
//    freopen("a.txt","w",stdout);
    scanf("%d",&times);
    while(times--){
        int y,m,d,month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        scanf("%d/%d/%d",&y,&m,&d);
        if(y%400==0 ||(y%4==0 && y%100!=0)) month[2]=29;
        if(m<1 || m>12 || y<2000 || d<1 || d>month[m]){
            if(times) printf("No\n");
            else printf("No");
        }
        else{
            if(times) printf("Yes\n");
            else printf("Yes");
        }
    }
    return 0;
}
