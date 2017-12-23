#include<stdio.h>
int LeapYear(int);
int Calculate(int,int,int);

int main(){
    int y,m,d;
    int times;
    scanf("%d",&times);
    while(times){
        scanf("%d/%d/%d",&y,&m,&d);
        printf("%d\n",Calculate(y,m,d));
        times--;
    }
    return 0;
}

int LeapYear(int year){
    if(year%400==0 || (year%4==0 && year%100!=0))
        return 1;
    else
        return 0;
}

int Calculate(int y,int m,int d){
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(LeapYear(y)) month[1]=29;
    if(y<1970 || m>12 || m<1 || d<1 || d>month[m-1])
        return 0;

    int result=0,i;
    if(y>1970) result--;
    if(y>1970){
        while(y!=1970){
            if(LeapYear(y-1)) result+=366;
            else result+=365;
            y--;
        }
    }
    if(m>1){
        for(i=0;i<m-1;i++)
            result+=month[i];
    }
    result+=d;
    return result;
}
