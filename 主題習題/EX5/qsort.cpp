#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<memory.h>
/* functions */
int random(int*,int,int,bool);
bool cmp(int,int);
bool cmp2(int,int);
void quick(int*,int,int,bool (*cmp)(int,int));
void myswap(int*,int*);
void printArr(int*,int,bool);
bool rev = false;
int main(void){
    srand(time(NULL));
//    FILE *file = fopen("random.bin","rb");
    freopen("random.bin","rb",stdin);
    freopen("out.txt","w",stdout);
    int ncase,n;
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d",&n);
        int *arr = new int[n];
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        quick(arr,0,n-1,cmp);
        printArr(arr,n,rev);
        delete[] arr;
    }
    return 0;
}
/* compares */
bool cmp(int a,int b){
    return a<b;
}
bool cmp2(int a,int b){
    return a>b;
}
/* quick sort */
void quick(int *arr,int start,int ending,bool (*compare)(int,int)){
    if(start>=ending) return;
    rev = compare(1,0);
    int pivot = random(arr,start,ending,rev);
    quick(arr,start,pivot-1,cmp);
    quick(arr,pivot+1,ending,cmp);
}
/* Choose random pivot */
int random(int *arr,int start,int ending,bool rev){
    int pivotIndex = start+rand()%(ending-start+1); //generate index between start to ending
    int pivot = arr[pivotIndex];
    int left = start - 1;
    myswap(&arr[pivotIndex],&arr[ending]); //let pivot being new end
    for(int i=start;i<ending;i++){
        if(arr[i] < pivot && rev == false) myswap(&arr[++left],&arr[i]);
        else if(arr[i] > pivot && rev == true) myswap(&arr[++left],&arr[i]);
    }
    myswap(&arr[left+1],&arr[ending]);
    return left+1;  //random pivot
}
/* Swapping a and b */
void myswap(int *a, int *b){
    if(a == b) return;
    int t=*a;
    *a=*b;
    *b=t;
    return;
}
/* Print array */
void printArr(int *arr,int n,bool rev){
    if(!rev){
        for(int i=0; i<n-1; i++)
            printf("%d ",arr[i]);
        printf("%d\n",arr[n-1]);
    }
    else{
        for(int i=n-1;i>0;i--) printf("%d ",arr[i]);
        printf("%d\n",arr[0]);
    }
    return;
}
