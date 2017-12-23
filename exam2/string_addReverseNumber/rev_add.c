#include<stdio.h>
#include<string.h>
#define SIZE 210

int main(){
    char num1[SIZE],num2[SIZE];
    int times,Result[SIZE];
    scanf("%d",&times);
    while(times--){
        scanf("%s%s",num1,num2);
        int i;
        for(i=0;i<SIZE;i++) Result[i]=0;
        int size1=strlen(num1),size2=strlen(num2),max_size=size1;
        if(size2>max_size) max_size=size2;
        for(i=0;i<max_size;i++){
            if(max_size==size1)
                Result[i]=num1[i]-48;
            else
                Result[i]=num2[i]-48;
        }
        for(i=0;i<max_size;i++){
            if(max_size==size1){
                if(size2>i) Result[i]+=num2[i]-48;
            }
            else{
                if(size1>i) Result[i]+=num1[i]-48;
            }
            if(Result[i]>=10){
                Result[i]-=10;
                Result[i+1]+=1;
            }
        }
        int non_zero=-1;
        for(i=0;i<=max_size;i++)
            if(Result[i]){
                non_zero=i;
                break;
            }
        for(i=non_zero;i<max_size;i++) printf("%d",Result[i]);
        if(Result[max_size]) printf("%d",Result[max_size]);
        if(times) printf("\n");
    }
    return 0;
}
