#include<stdio.h>
#include<string.h>
#define SIZE 1000
int main(){
    int times;
    scanf("%d",&times);
    while(times--){
        char num1[SIZE],num2[SIZE];
        scanf("%s%s",num1,num2);
        int result[SIZE]={0},i,j,k;
        int L1=strlen(num1),L2=strlen(num2),Max=L1;
        if(L2>Max) Max=L2;
        for(i=L1-1,j=L2-1,k=0;Max-->0;i--,j--,k++){
            if(i>=0 && j>=0)
                result[k]+=num1[i]+num2[j]-48*2;
            else if(i<0)
                result[k]+=num2[j]-48;
            else if(j<0)
                result[k]+=num1[i]-48;
            if(result[k]>=10){
                result[k]-=10;
                result[k+1]+=1;
            }
        }
        if(result[k]) printf("%d",result[k]);
        for(i=k-1;i>0;i--)
            printf("%d",result[i]);
        printf("%d\n",result[i]);
    }
    return 0;
}
