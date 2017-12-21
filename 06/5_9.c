#include<stdio.h>

int main(){
    int times,a;
    scanf("%d",&times);
    while(times){
        scanf("%d",&a);
        int counter=0,temp=a,i,sum=1;
        for(i=2;i<=a;i++){
            while(temp%i==0){
                counter++;
                temp/=i;
                sum*=i;
            }
            if(counter){
                printf("%d\n%d",i,counter);
                if(times!=1)
                    printf("\n");
                else{
                    if(sum!=a)
                        printf("\n");
                }
            }
            counter=0;
        }
        if(times!=1)
            printf("\n");
        times--;
    }

}
