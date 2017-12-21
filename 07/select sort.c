#include<stdio.h>

int main(){
    int n,loop=1;
    while(loop){
        scanf("%d",&n);
        if(n==0)
            break;
        int arr[n];
        int i,j,times=0;
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    arr[i]+=arr[j];
                    arr[j]=arr[i]-arr[j];
                    arr[i]=arr[i]-arr[j];
                    times++;
                }
            }
        }
        for(i=0;i<n-1;i++)
            printf("%d ",arr[i]);
        printf("%d",arr[i]);
        printf("%d\n",times);
    }
}
