#include<stdio.h>
int main(){
    int times,a,i,j;
    scanf("%d",&times);
    while(times){
        scanf("%d",&a);
        for(i=1;i<=a;i++){
            for(j=1;j<=i;j++){
                printf("%d ",j);
                if(j!=a)
                    printf("\n");
            }
        }
        if(times!=1)
            printf("\n");
    }
}
