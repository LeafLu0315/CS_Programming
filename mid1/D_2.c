#include<stdio.h>
void bbsort(int [],int);
int main(){
    int times,loop=0;
//    freopen("D2out.txt","w",stdout);
    scanf("%d",&times);
    while(times--){
        int length,input;
        scanf("%d",&length);
        int odd=0,even=0,Oarr[length],Earr[length];
        while(length--){
            scanf("%d",&input);
            if(input%2) Oarr[odd++]=input;
            else Earr[even++]=input;
        }
        if(odd) bbsort(Oarr,odd);
        if(even) bbsort(Earr,even);

        if(loop++) printf("\n");
        if(odd) printf("%d\n",Oarr[0]);
        else printf("No\n");
        if(even) printf("%d",Earr[even-1]);
        else printf("No");
        if(times) printf("\n");
    }
    return 0;
}

void bbsort(int arr[],int size){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            int t;
            if(arr[i]>arr[j]){
                t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
}
