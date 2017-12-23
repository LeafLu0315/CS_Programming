#include<stdio.h>
void bbsort(int [],int);
int main(){
    int n,loop=0;
//    freopen("D_4.txt","w",stdout);
    scanf("%d",&n);
    while(n--){
        int length,input;
        scanf("%d",&length);
        int Parr[length],Narr[length],P=0,N=0;
        while(length--){
            scanf("%d",&input);
            if(input<0) Narr[N++]=input;
            else Parr[P++]=input;
        }
        if(loop++) printf("\n");
        if(N){
            bbsort(Narr,N);
            printf("%d\n",Narr[N-1]);
        }
        else printf("No\n");
        if(P){
            bbsort(Parr,P);
            if(n) printf("%d\n",Parr[0]);
            else printf("%d",Parr[0]);
        }
        else{
            if(n) printf("No\n");
            else printf("No");
        }
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
