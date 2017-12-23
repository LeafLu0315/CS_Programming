#include<stdio.h>
int maxSubArraySum(int [],int);
int main(){
    int i,j,m,n;
    int prefix[5011];
    freopen("array_maxConsecutiveSum.in","r",stdin);
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        int arr[m],i;
        for(i=0;i<m;i++) scanf("%d",arr+i);
        int max=maxSubArraySum(arr,m);
        printf("%d\n",max);
    }
    return 0;
}

int maxSubArraySum(int a[], int size){
    int sum = 0, end = 0;
    int i;
    for (i = 0; i < size; i++){
        end = end + a[i];
        if (sum < end)
            sum = end;

        if (end < 0)
            end = 0;
    }
    return sum;
}
