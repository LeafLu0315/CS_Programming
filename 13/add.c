#include<stdio.h>
#include<string.h>
int main(){
    int times;
//    freopen("ar58.in","r",stdin);
    scanf("%d",&times);
    while(times--){
        char num1[1000],num2[1000],index1=0,index2=0;
        int i,j,k;
        for(i=0;i<1000;i++){
            num1[i]=48;
            num2[i]=48;
        }
        scanf("%s%s",num1,num2);
        char temp[1000]={0};
        if(strlen(num1)<strlen(num2)){
            for(i=0;i<1000;i++){
                temp[i]=num1[i];
                num1[i]=num2[i];
                num2[i]=num1[i];
            }
        }
        int result[1000]={0},max=strlen(num1);
        if(strlen(num2)>max) max=strlen(num2);
        for(i=strlen(num1)-1,j=strlen(num2)-1,k=0;max-->=0;i--,j--,k++){
            if(i>=0 && j>=0)
                result[k]+=num1[i]+num2[j]-48*2;
            else if(j<0)
                result[k]+=num1[i]-48;
            else if(i<0)
                result[k]+=num2[i]-48;
            if(result[k]>=10){
                result[k]-=10;
                result[k+1]+=1;
            }
        }
        if(result[k-1]!=-48) printf("%d",result[k-1]+48);
        for(i=k-2;i>=0;i--)
            printf("%d",result[i]);
        printf("\n");
    }
    return 0;
}
