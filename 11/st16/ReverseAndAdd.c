#include<stdio.h>
int Reverse(int);
int main(){
    int times;
    scanf("%d",&times);
    while(times--){
        int input,counter=0;
        scanf("%d",&input);
        while(1){
            if(input==Reverse(input)){
                printf("%d %d\n",counter,input);
                break;
            }
            input+=Reverse(input);
            counter++;
        }
    }
    return 0;
}

int Reverse(int a){
    int n=0;
    while(a){
        n=n*10+a%10;
        a/=10;
    }
    return n;
}
