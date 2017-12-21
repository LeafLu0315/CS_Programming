#include<stdio.h>

int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(!n)
            break;
        int arr[n],i,j,times=0;
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        for(i=0;i<n-1;i++){
            for(j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    arr[j]+=arr[j+1];
                    arr[j+1]=arr[j]-arr[j+1];
                    arr[j]=arr[j]-arr[j+1];
                    times++;
                }
            }
        }
        printf("%d\n",times);
    }
    return 0;
}
