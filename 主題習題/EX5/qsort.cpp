#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<memory.h>
#define N 1000  //array size
#define GENERATE_RANGE 810000   //random number range
/* functions */
int random(int*,int,int);
void quick(int*,int,int);
void myswap(int*,int*);
void printArr(int*,int);
void generateArr(int*,int);

int main(void){
    srand(time(NULL));
    int *arr = new int[N];
    generateArr(arr,N);
    printf("Before:\n");
    printArr(arr,N);
    quick(arr,0,N-1);
    printf("After:\n");
    printArr(arr,N);
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
    int pivotIndex = start+rand()%(ending-start+1);
    int pivot = arr[pivotIndex];
    int left = start - 1;
    myswap(&arr[pivotIndex], &arr[ending]);
    for(int i=start;i<ending;i++) if(arr[i] < pivot) myswap(&arr[++left],&arr[i]);
    myswap(&arr[left+1],&arr[ending]);
    return left+1;  //random pivot
}
/* Swapping a and b*/
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
    printf("%d\n",arr[n-1]);
    return;
}
