#include<stdio.h>

int main(){
    int length,loop=1;
    while(loop){
        scanf("%d",&length);
        if(!length) loop=0;
        if(loop>1) printf("\n");
        int arr[length],i,odd,even;
        for(i=0;i<length;i++) {
            scanf("%d",&arr[i]);
            if(arr[i]%2) odd++;
            else even++;
        }
        for(i=0;i<length;i++){
            if(arr[i]%2){
                    printf("odd=");
                if(odd--)
                    printf("%d ",arr[i]);
                else
                    printf("%d\n",arr[i]);
            }
            else{
                printf("even=");
                if(even--)
                    printf("%d ",arr[i]);
                else
                    printf("%d\n",arr[i]);
            }
        }
        loop++;
    }
    return 0;
}
