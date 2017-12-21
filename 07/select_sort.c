#include<stdio.h>

int main(){
    int n,loop=1;
    while(loop){
        scanf("%d",&n);
        if(n==0)
            break;
        int arr[n];
        int i,j,times=0,min;
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        for(i=0;i<n-1;i++){
            min=i;
            for(j=i+1;j<n;j++){
                if(arr[min]>arr[j]){
                    min=j;
                    times++;
                }
                int temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
            }
        }
        if(times<3){
            for(i=0;i<n;i++)
                printf("%d ",arr[i]);
            printf("%d\n",times);
        }
        else{
            for(i=0;i<3;i++)
                printf("%d ",arr[i]);
            printf("%d\n",times);
        }
    }
    return 0;
}
