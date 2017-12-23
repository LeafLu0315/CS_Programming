#include<stdio.h>

int main(){
   int loop;
//   freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
   scanf("%d",&loop);
   while(loop--){
        int a,b,i,j;
        scanf("%d%d",&a,&b);
        int min=a,max=a;
        if(min>b) min=b;
        if(max<b) max=b;
        int sum=0,division,d_temp,temp=min;
        for(i=min;i<=max;i++){
            for(j=1;j<i;j++){
                if(i%j==0)
                    sum+=j;
            }
            if(i==min && i-sum>=0)
                division=i-sum;
            else if(i==min)
                division=2147483647;
            d_temp=i-sum;
            if(division>d_temp && d_temp>=0){
                temp=i;
                division=d_temp;
            }
            sum=0;
        }
        printf("%d %d\n",division,temp);
   }
}
