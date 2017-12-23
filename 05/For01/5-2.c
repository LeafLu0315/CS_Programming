#include<stdio.h>
int main(){
//    int times;
//    scanf("%d",&times);
//    int num[times];
//    int i,j;
//    for(i=0;i<times;i++)
//        scanf("%d",&num[i]);
//    for(i=0;i<times;i++)
//    {
//        for(j=1;j<=num[i];j++)
//            printf("%d\n",j);
//        for(j=num[i]-1;j>0;j--)
//            printf("%d\n",j);
//        if(j==0)
//            printf("\n");
//    }
    int times,i,input;
    scanf("%d",&times);
    while(times){
        scanf("%d",&input);
        for(i=1;i<=input;i++)
            printf("%d\n",i);
        for(i=input-1;i>0;i--)
            printf("%d\n",i);
        printf("\n");
        times--;
    }
    return 0;
}
