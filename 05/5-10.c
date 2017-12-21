#include<stdio.h>
int powerfunc(int,int);

int main(){
    int times,input;
    scanf("%d%d",&input,&times);
    printf("%d\n",input);
    while(times--){
        int temp=input,counter=0;
        while(temp!=0){
            temp/=10;
            counter++;
        }
        int i,j;
        int arr[counter];
        for(i=0;i<counter;i++){
            arr[i]=input%10;
            input/=10;
        }
        int arr2[counter];
        arr2[0]=arr[0];
        for(i=1,j=counter-1;i<counter;i++,j--)
            arr2[i]=arr[j];
        int output=0;
        for(i=0;i<counter;i++)
            output+=arr2[i]*powerfunc(10,counter-i-1);
        printf("%d\n",output);
        input=output;
    }
    return 0;
}


int powerfunc(int a,int x){
    int i,result=1;
    for(i=1;i<=x;i++)
        result*=a;
    return result;
}
