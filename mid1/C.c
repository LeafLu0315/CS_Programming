#include<stdio.h>
void bbsort(int [],int);

int main(){
    int p,q,n;
//    freopen("C.txt","r",stdin);
//    freopen("Cout.txt","w",stdout);
    while(scanf("%d%d%d",&p,&q,&n)!=EOF){
        int arr[n],i=0,j=0,temp=n,ans[n];
        while(temp--) scanf("%d",&arr[i++]);
        bbsort(arr,n);
        for(i=0;i<n;i++)
            if((arr[i] % p==0 && arr[i]%q!=0) ||(arr[i] % q==0 && arr[i]%p!=0))
                ans[j++]=arr[i];
        for(i=0;i<j-1;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[i]);
    }
    return 0;
}

void bbsort(int arr[],int size){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            int t;
            if(arr[i]>arr[j]){
                t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
}
