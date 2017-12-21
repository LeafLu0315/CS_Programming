#include<stdio.h>
#include<math.h>
double f(int,double,double[]); //calculate

int main(){
    int T;
//    freopen("i.txt","r",stdin);
//    freopen("iout.txt","w",stdout);
    scanf("%d",&T);
    while(T--){
        int P,i;
        scanf("%d",&P);
        int size=P+1;
        double arr[size],a,b;
        for(i=0;i<size;i++) scanf("%lf",&arr[i]);
        scanf("%lf%lf",&a,&b);
        double x,fa=f(size,a,arr),fb=f(size,b,arr),fx;
        if(fa*fb>0) continue;
        while(b-a>0.000001){
            x=(a+b)/2;
            fx=f(size,x,arr);
            if(fa*fx>0){
                a=x;
                fa=fx;
            }
            else{
                b=x;
                fb=fx;
            }
        }
        printf("%.5lf\n",round(a*1000000)/1000000);
    }
    return 0;
}

double f(int p,double x,double c[]){
    double sum=0,reverse[p];
    int i,j;
    for(i=p-1,j=0;i>=0;i--,j++) reverse[j]=c[i];
    for(i=0;i<p;i++){
        double temp=1;
        for(j=0;j<i;j++) temp*=x;
        sum+=reverse[i]*temp;
    }
    return sum;
}
