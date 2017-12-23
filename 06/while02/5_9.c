#include<stdio.h>
int main(){
    int times,a,counter=0,temp,i,sum=1,flag=0;
    scanf("%d",&times);
    while(times--){
        scanf("%d",&a);
        counter=0;temp=a;sum=1;
        if(flag++) printf("\n");
        for(i=2;i<=a;i++){
            while(temp%i==0){
                counter++;
                temp/=i;
                sum*=i;
            }
            if(counter) printf("%d\n%d\n",i,counter);
            counter=0;
        }
    }
    return 0;
}
