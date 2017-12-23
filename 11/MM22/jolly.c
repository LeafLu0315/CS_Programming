#include<stdio.h>
int Abs(int,int);
void bbsort(int [],int);
int main(){
    int times;
    scanf("%d",&times);
    while(times--){
        int size;
        scanf("%d",&size);
        int arr[size],i,j;
        int jolly=1,n=1,counter=0;
        for(i=0;i<size;i++) scanf("%d",&arr[i]);
        int Minus[size];
        for(i=0;i<size-1;i++)
            Minus[i]=Abs(arr[i],arr[i+1]);
        bbsort(Minus,size);
        for(i=0;i<size;i++){
            if(Minus[i]==n){
                counter++;
                n++;
            }
        }
        if(counter==size-1) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}

int Abs(int a,int b){
    if(a-b>0) return a-b;
    return b-a;
}

void bbsort(int arr[],int size){
    int i,j,t;
    for(i=0;i<size-1;i++)
        for(j=i+1;j<size;j++)
            if(arr[i]>arr[j]){
                t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
    return ;
}
