#include<stdio.h>
#define MAX 1000000
int num[MAX][10]={0};

int main(){
    int i,j,temp,ncase;
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
        int p1[10]={0},p2[10]={0},sc1=0,sc2=0;
        for(i=0;i<6;i++){
            scanf("%d",&temp);
            p1[temp]++;
        }
        for(i=0;i<6;i++){
            scanf("%d",&temp);
            p2[temp]++;
        }
        for(i=0;i<MAX;i++){
            int flag1=1,flag2=1;
            for(j=0;j<10;j++){
                if(num[i][j]>p1[j]) flag1=0;
                if(num[i][j]>p2[j]) flag2=0;
            }
            if(flag1 && flag2) continue;
            if(flag1) sc1++;
            if(flag2) sc2++;
        }
        printf("%d %d",sc1,sc2);
        if(ncase) printf("\n");
    }
    return 0;
}
