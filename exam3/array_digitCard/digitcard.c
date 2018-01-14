#include<stdio.h>
#define MAX 1000000
int num[MAX][10]={0};

int main(){
    int i,j,temp,ncase,sc,p1[10],flag;
    freopen("array_digitCard.in","r",stdin);
    num[0][0]=1;
    for(i=1;i<MAX;i++){
        temp=i;
        while(temp){
            num[i][temp%10]++;
            temp/=10;
        }
    }
    scanf("%d",&ncase);
    while(ncase--){
        for(i=0;i<10;i++) p1[i]=0;
        for(i=0;i<6;i++){
            scanf("%d",&temp);
            p1[temp]++;
        }
        sc=0;
        for(i=0;i<MAX;i++){
            flag=0;
            for(j=0;j<10;j++)
                if(num[i][j]==p1[j]){
                    flag++;
                }
            if(flag==j-1) sc++;
        }
        printf("%d\n",sc);
    }
    return 0;
}
