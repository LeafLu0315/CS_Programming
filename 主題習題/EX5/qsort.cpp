#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<memory.h>
#define N 10000000  //array size
#define GENERATE_RANGE 123456789   //random number range
/* functions */
int random(int*,int,int);
void quick(int*,int,int);
void myswap(int*,int*);
void printArr(int*,int);
void generateArr(int*,int);
bool error_detect(int*,int);
int main(void){
    srand(time(NULL));
//    freopen("o.txt","w",stdout);
    int *arr = new int[N];
    generateArr(arr,N);
    quick(arr,0,N-1);
//    printArr(arr,N);
    printf("%s",error_detect(arr,N) ? "OK":"ERROR");
    delete arr;
    return 0;
}
/* generate array */
void generateArr(int *arr,int n){
    for(int i=0;i<n;i++) arr[i] = (rand()*rand())%GENERATE_RANGE;
}
/* quick sort */
void quick(int *arr,int start,int ending){
    if(start>=ending) return;
    int pivot = random(arr,start,ending);
    quick(arr,start,pivot-1);
    quick(arr,pivot+1,ending);
}
/* Choose random pivot */
int random(int *arr,int start,int ending){
    int pivotIndex = start+rand()%(ending-start+1); //generate index between start to ending
    int pivot = arr[pivotIndex];
    int left = start - 1;
    myswap(&arr[pivotIndex],&arr[ending]); //let pivot being new end
    for(int i=start;i<ending;i++) if(arr[i] < pivot) myswap(&arr[++left],&arr[i]);
    myswap(&arr[left+1],&arr[ending]);
    return left+1;  //random pivot
}
/* Swapping a and b */
void myswap(int *a, int* b){
    if(a == b) return;
    int t=*a;
    *a=*b;
    *b=t;
    return;
}
/* Print array */
void printArr(int *arr,int n){
    for(int i=0; i<n-1; i++)
        printf("%d ",arr[i]);
    printf("%d",arr[n-1]);
    return;
}
/* Error detection */
bool error_detect(int *arr,int n){
    bool ed = false;
    for(int i=0;i<n-1;i++) if(arr[i]>arr[i-1]){ ed=true; break;}
    return ed;
}
