#include<stdio.h>
int main(){
    int times,left,right,a,b,i,j;
    scanf("%d",&times);
    while(times--){
        scanf("%d%d",&a,&b);
        if(a>b){
            left=b;
            right=a;
        }
        else{
            left=a;
            right=b;
        }
        for(i=left;i<=right;i++){
            for(j=1;j<=i-1;j++)
                printf("%d ",j);
            printf("%d\n",j);
        }
        if(times) printf("\n");
    }
    return 0;
}
