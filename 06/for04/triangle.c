#include<stdio.h>
int main(){
    int times,a,i,j;
    scanf("%d",&times);
    while(times--){
        scanf("%d",&a);
        for(i=1;i<=a;i++){
            for(j=1;j<=i-1;j++)
                printf("%d ",j);
            printf("%d\n",j);
        }
        if(times) printf("\n");
    }
    return 0;
}
