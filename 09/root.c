#include<stdio.h>
double f(double,double [],int);

int main(){
    int T;
    freopen("i.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        int s;
        scanf("%d",&s);
        int size=s+1,i;
        double arr[size],a,b;
        for(i=0;i<size;i++) scanf("%lf",arr+i);
        scanf("%lf %lf",&a,&b);
        double x=(a+b)/2,root=x,result=f(a,arr,size)*f(b,arr,size);
        while(1){
            if(result>=-0.000001 && result<=0.000001) break;
            if(f(a,arr,size)*f(x,arr,size)<0){
                root=x;
                result=f(a,arr,size)*f(x,arr,size);
                x=(a+x)/2;
            }
            if(f(b,arr,size)*f(x,arr,size)<0){
                root=x;
                result=f(b,arr,size)*f(x,arr,size);
                x=(b+x)/2;
            }
        }
        printf("%lf\n",root);
    }
    return 0;
}

double f(double x,double arr[],int size){
    double sum=0,reverse[size];
    int i,j;
    for(i=size-1,j=0;i>=0;i--,j++) reverse[j]=arr[i];
    for(i=0;i<size;i++){
        double temp=1;
        for(j=0;j<i;j++) temp*=x;
        sum+=reverse[i]*temp;
    }
    return sum;
}

