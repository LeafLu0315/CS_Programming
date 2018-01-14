#include<stdio.h>
int main(){
    int arr[3]={0,0,0};//x,y,direction
    int loop=0,time,command;
    int temp = 0;
    while(loop==0){
        scanf("%d%d",&time,&command);
        time-=temp;
        int P=10*time,N=-10*time;

        switch(arr[2]%4){
        case 0:
            arr[1]+=P;
            break;
        case 2:
            arr[1]+=N;
            break;
        case 1:
            arr[0]+=N;
            break;
        case 3:
            arr[0]+=P;
            break;
        }

        if(command!=1&&command!=2)
            break;
        else if(command==1)
            arr[2]+=1;
        else
            arr[2]+=3;


        temp+=time;
    }
    printf("%d\n%d\n",arr[0],arr[1]);
    return 0;
}
