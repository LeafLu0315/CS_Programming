#include<stdio.h>

int main(){
    int times;
    scanf("%d",&times);
    while(times--){
        int a,b,c,d;    //(ax^2+bx+c)^d
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int origin[3]={c,b,a};
        /*when d=1*/
        if(d==1){
            printf("%d %d %d\n",a,b,c);
            continue;
        }
        /*put the base in multiple*/
        int point=0,temp=0,multiple[1025]={0},i,j;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++)
                multiple[point++]+=origin[i]*origin[j];
            if(i!=2) point=++temp;      //record the size=point
        }
        /*when d=2*/
        int reverse[point];
        for(i=point-1,j=0;i>=0;i--,j++) reverse[j]=multiple[i];
        if(d==2){
            for(i=0;i<point-1;i++)
                printf("%d ",reverse[i]);
            printf("%d\n",reverse[i]);
            continue;
        }
        /*when d>2*/
        int newmultiple[1025]={0},newpoint=point,newtemp=0;
        temp=0;
        while(d-->2){
            for(i=0;i<newpoint;i++){
                for(j=0;j<3;j++)
                    newmultiple[newtemp++]+=multiple[i]*origin[j];
                if(i!=newpoint-1) newtemp=++temp;  //size=newtemp
            }
            newpoint=newtemp;
            if(d>2){
                for(i=0;i<newpoint;i++){
                    multiple[i]=newmultiple[i];
                    newmultiple[i]=0;
                }
                newtemp=0;
                temp=0;
            }
        }
        int reverse_newmultiple[1025]={0};
        for(i=newpoint-1,j=0;i>=0;i--,j++) reverse_newmultiple[j]=newmultiple[i];
        for(i=0;i<newpoint-1;i++)
                printf("%d ",reverse_newmultiple[i]);
        printf("%d\n",reverse_newmultiple[i]);

    }
    return 0;
}
