#include<stdio.h>

int main(){
    int length;
    freopen("input.txt","r",stdin);
    while(1){
        scanf("%d",&length);
        if(!length) break;
        int arr[length],i,odd=0,even=0;
        for(i=0;i<length;i++)
            scanf("%d",&arr[i]);
        for(i=0;i<length;i++){
            if(arr[i]%2)
                odd++;
            else
                even++;
        }
        for(i=0;i<length;i++){
            if(arr[i]%2){
                if(!odd){
                    printf("%d ",arr[i]);
                    odd--;
                }
                else
                    printf("%d\n",arr[i]);
            }
        }
        for(i=0;i<length;i++){
            if(arr[i]%2==0){
                if(!even){
                    printf("%d ",arr[i]);
                    even--;
                }
                else
                    printf("%d",arr[i]);
            }
        }
    }
}
