#include<stdio.h>

int main(){
    int a[3]={0};
    int i;
    for(i=0;i<3;i++)
        scanf("%d",&a[i]);
    int j,temp;
    for(i=0;i<2;i++){
        for(j=0;j<2-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    if((a[0]+a[1]>a[2])&&(a[0]-a[1]<a[2]))
        printf("1");
    else
        printf("0");
    return 0;
}
