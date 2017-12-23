#include<stdio.h>
int LeapYear(int);
int LeapDays(int);

int main(){
    int x=28;
    int y0=1970,m0=1,d0=1,y,m,d;
    int month[12]={31,x,31,30,31,30,31,31,30,31,30,31};
    int times,result;
    scanf("%d",&times);
    while(times){
        result=0;
        scanf("%d/%d/%d",&y,&m,&d);
        if(LeapYear(y-1)) x=29;
        else x=28;

        if(y<y0 || m>12 || m<1 || d>month[m-1] || d<1){
            printf("%d\n",result);
            times--;
            continue;
        }

        int temp=y;

        while(temp!=y0){
            result+=LeapDays(temp-1);
            temp--;
        }

        if(m>m0){
            int i=0;
            for(i;i<m-1;i++)
                result+=month[i];
        }

        if(d>d0)
            result+=d;

        if(d==d0 && m==m0)
            if(y!=y0) result++;
        times--;
        printf("%d\n",result);
    }
    return 0;
}

int LeapYear(int year){
    if(year%400==0 || year%4==0 && year%100!=0)
        return 1;
    else
        return 0;
}

int LeapDays(int year){
    if(LeapYear(year-1))
        return 366;
    else
        return 365;
}
