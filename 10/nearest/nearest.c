#include<stdio.h>
int Abs(int);

int main(){
    int times;
//    freopen("nearest.in","r",stdin);
//    freopen("nearest.out","w",stdout);
    scanf("%d",&times);
    while(times--){
        int treasure;
        scanf("%d",&treasure);
        int x=0,y=0;
        int arr[treasure][3],i,j;
        for(i=0;i<treasure;i++){
            scanf("%d%d",&arr[i][1],&arr[i][2]); //found X Y
            arr[i][0]=1;    //all is not found
        }
        int sum=0;
        int near,item;
        for(i=0;i<treasure;i++){
            near = 2147483647;
            item = -1;
            for(j=0;j<treasure;j++){
                if( arr[j][0] && Abs(arr[j][1]-x)+Abs(arr[j][2]-y) < near){
                    item = j;
                    near = Abs(arr[j][1]-x)+Abs(arr[j][2]-y);
                }
            }
            sum+=near;
            arr[item][0]=0;
            x=arr[item][1];
            y=arr[item][2];
        }
        printf("%d\n",sum);
    }
    return 0;
}

int Abs(int a){
    if(a>0) return a;
    return -a;
}

