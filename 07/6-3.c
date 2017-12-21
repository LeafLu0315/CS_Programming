#include<stdio.h>

int main(){
    int num;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(num!=0){
        scanf("%d",&num);
        int arr[num];
        int i;
        for(i=0;i<num;i++)
            scanf("%d",&arr[i]);
        for(i=0;i<num;i++){
            if(arr[i]%2!=0)
                printf("%d ",arr[i]);
        }
        printf("\n");
        for(i=0;i<num;i++){
            if(arr[i]%2==0)
                printf("%d ",arr[i]);
        }
        printf("\n");
    }
    return 0;
}

