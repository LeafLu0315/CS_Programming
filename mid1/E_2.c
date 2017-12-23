#include<stdio.h>
int absolute(int);
int main(){
    int length;
//    freopen("E_2.txt","w",stdout);
    while(1){
        scanf("%d",&length);
        if(!length) break;
        int arr[length],i,j,t,i_temp=0,mini=2147483647;
        for(i=0;i<length;i++) scanf("%d",arr+i);
        for(i=0;i<length;i++){
            t=0;
            for(j=0;j<length;j++)
                if(i!=j) t+=arr[j] * (j-i);
            if(absolute(t)<mini){
                mini=absolute(t);
                i_temp=i;
            }
        }
        printf("%d %d\n",i_temp,mini);
    }
    return 0;
}

int absolute(int a){
    if(a>0) return a;
    return -a;
}
