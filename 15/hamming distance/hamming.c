#include<stdio.h>
int hamming(int,int);
int main(){
    int times,num[500]={0},n,i,j,max;
    scanf("%d",&times);
    while(times--){
        scanf("%d",&n);
        max=0;
        for(i=0;i<n;i++) scanf("%d",num+i);
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
                if(hamming(num[i],num[j])>max) max=hamming(num[i],num[j]);
        printf("%d\n",max);
    }
    return 0;
}

int hamming(int a,int b){
    int res=0,x=a^b;
    while(x){
        if(x&1) res++;
        x>>=1;
    }
    return res;
}
