#include<stdio.h>
#define MAX 50
int absolute(int);
int main(){
    int times,n,i,j,len,wid;
    int arr[MAX][2],max;
    freopen("simulation_maxArea.in","r",stdin);
    scanf("%d",&times);
    while(times--){
        scanf("%d",&n);
        max=0;
        for(i=0;i<n;i++) for(j=0;j<2;j++) scanf("%d",&arr[i][j]);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                len=absolute(arr[j][0]-arr[i][0]);
                wid=absolute(arr[j][1]-arr[i][1]);
                if(len*wid>max) max=len*wid;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}

int absolute(int a){
    if(a>0) return a;
    return -a;
}
