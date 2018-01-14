#include<stdio.h>
void bbsort(int [],int);
int counts(int [],int,int);

int main(){
    int T;
//    freopen("AR12.in","r",stdin);
//    freopen("counting.txt","w",stdout);
    scanf("%d",&T);
    while(T--){
        int num[100];
        int input,counter=0;
        while(1){
            scanf("%d",&input);
            if(input==-999) break;
            num[counter++]=input;       //size=counter
        }
        bbsort(num,counter);
        int i,j,nums[counter],index=0;
        for(i=0;i<counter;i++) nums[i]=0; //initialize
        nums[index++]=num[0];
        for(i=1;i<counter;i++){
            if(num[i]==num[i-1])continue;
            nums[index++]=num[i];
        }
        for(i=0;i<index;i++) printf("%d %d\n",nums[i],counts(num,counter,nums[i]));
        if(T) printf("\n");
    }
    return 0;
}

void bbsort(int arr[],int size){
    int i,j;
    for(i=0;i<size-1;i++)
        for(j=i+1;j<size;j++)
            if(arr[i]<arr[j]){
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
    return;
}

int counts(int arr[],int size,int x){
    int i,counter=0;
    for(i=0;i<size;i++)
        if(arr[i]==x) counter++;
    return counter;
}
