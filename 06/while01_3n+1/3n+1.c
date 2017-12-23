#include<stdio.h>
int func(int);

int main(){
    int i,j,length;
    while(1){
        scanf("%d%d",&i,&j);
        if(!j && !i)
            break;
        int min=i,max=i;
        if(min>j) min=j;
        if(max<j) max=j;
        int k;
        length=1;
        for(k=min;k<=max;k++){
            if(func(k)>length)
                length=func(k);
        }
        printf("%d %d %d\n",i,j,length);
    }
    return 0;
}
int func(int n){
    int counter=1;
    while(n!=1){
        if(n%2==1){
            n=n*3+1;
            counter++;
        }
        else{
            n/=2;
            counter++;
        }
    }
    return counter;
}
