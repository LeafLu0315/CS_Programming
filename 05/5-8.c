#include<stdio.h>
int powerfunc(int,int);

int main(){
    int f,s,way;
    scanf("%d%d",&f,&way);
    int num[way];
    int i,j;
    for(i=0;i<way;i++)
        scanf("%d",&num[i]);
    int decimal=0;
    for(i=way-1,j=0;i>=0;i--,j++)
        decimal+=powerfunc(f,j)*num[i];
    scanf("%d",&s);
    int num2[40];
    i=0;
    while(decimal!=0){
        num2[i]=decimal%s;
        decimal/=s;
        i++;
    }
    j=0;
    for(j=i-1;j>=0;j--){
        if(num2[j]<10)
            printf("%d\n",num2[j]);
        else
            printf("%c\n",num2[j]+55);
    }
    return 0;
}
int powerfunc(int first,int times){
    if(times==0)
        return 1;
    int i,sum=1;
    for(i=1;i<=times;i++){
        sum*=first;
    }
    return sum;
}
