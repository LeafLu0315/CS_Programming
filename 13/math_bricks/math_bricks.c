#include<stdio.h>
#include<stdlib.h>
void sol(int,int);

int main(void){
    int n,counter=1;
    while(scanf("%d",&n),n) sol(n,counter++);
    return 0;
}

void sol(int n,int counter){
    int sum=0;
    int *bricks = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&bricks[i]);
        sum += bricks[i];
    }
    int avg = sum / n,ans=0;
    for(int i=0;i<n;i++) ans += abs(bricks[i]-avg);
    printf("Set #%d\nThe minimum number of moves is %d.\n\n",counter,ans/2);
}
