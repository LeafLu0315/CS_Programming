#include<stdio.h>
int prime(int);

int main(){
    int times;
    scanf("%d",&times);
    int input;
    while(times--){
        scanf("%d",&input);
        int i,j,counter=0,temp=input;
        for(i=2;i<=input;i++){      //Calculate the size
            if(input%i==0 && prime(i)==1)
                counter++;
        }

        int arr[counter];
        for(i=2,j=0;i<=input;i++){
            if(input%i==0 && prime(i)==1){
                arr[j]=i;
                j++;
            }
        }

        int arr2[counter];

        for(i=0;i<counter;i++)  //Initialize
            arr2[i]=0;

        while(temp!=1){
            for(i=0,j=0;i<counter;i++,j++){
                if(temp%arr[i]==0){
                 arr2[j]++;
                 temp/=arr[i];
                }
            }
        }
        for(i=0;i<counter;i++){
            printf("%d\n%d\n",arr[i],arr2[i]);
        }

        printf("\n");

    }
    return 0;
}

int prime(int x){
    int counter=0,i;
    for(i=1;i<=x;i++){
        if(x%i==0)
            counter++;
    }
    if(counter==2)
        return 1;
    else
        return 0;
}
