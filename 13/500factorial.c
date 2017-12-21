#include<stdio.h>
#define SIZE 30000
void Factorial(int);
int main(){
    int input;
    while(scanf("%d",&input)!=EOF) Factorial(input);
    return 0;
}

void Factorial(int x){
    int arr[SIZE]={0},i,j,non_zero=SIZE-1;
    arr[SIZE-1]=1;
    for(i=1;i<=x;i++){
        for(j=SIZE-1;j>=0;j--) arr[j]*=i;
        for(j=SIZE-1;j>=0;j--)
            if(arr[j]>=10){
                arr[j-1]+=arr[j]/10;
                arr[j]%=10;
            }
    }
    printf("%d!\n",x);
    for(i=0;i<SIZE;i++)
        if(arr[i]!=0){
            non_zero=i;
            break;
        }
    for(i=non_zero;i<SIZE;i++)
        printf("%d",arr[i]);
    printf("\n");
    return;
}
