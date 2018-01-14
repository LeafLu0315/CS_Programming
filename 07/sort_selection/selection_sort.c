#include<stdio.h>
int selection_sort(int arr[],int);
int main(){
    int length;
    while(1){
        scanf("%d",&length);
        if(!length) break;
        int arr[length],i;
        for(i=0;i<length;i++)
            scanf("%d",&arr[i]);
        int ans=selection_sort(arr,length);
        if(length>2)
            for(i=0;i<3;i++)
                printf("%d ",arr[i]);
        else
            for(i=0;i<length;i++)
                printf("%d ",arr[i]);
        printf("%d\n",ans);
    }
    return 0;
}

int selection_sort(int arr[],int size){
    int i,j,counter=0;
    for(i=0;i<size;i++){
        int minIndex=i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[minIndex])
                minIndex=j;
        }
        if(minIndex!=i){
            int temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
            counter++;
        }
    }
    return counter;
}
