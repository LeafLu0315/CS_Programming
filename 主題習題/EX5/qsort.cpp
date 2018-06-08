#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<memory.h>
#define N 1000  //array size
#define GENERATE_RANGE 123456   //random number range
/* functions */
int random(int*,int,int);
int cmp(void*,void*);
void quick(int*,int,int,int (*cmp)(void*,void*));
void myswap(int*,int*);
void printArr(int*,int);
void generateArr(int*,int);
void reverseArr(int*,int);
int main(void){
    srand(time(NULL));
//    freopen("o.txt","w",stdout);
    int *arr = new int[N];
    generateArr(arr,N);
    quick(arr,0,N-1,cmp);
    printArr(arr,N);
    delete[] arr;
    return 0;
}
/* generate array */
void generateArr(int *arr,int n){
    for(int i=0;i<n;i++) arr[i] = (rand()*rand())%GENERATE_RANGE;
}
/* compares */
int cmp(void *a,void *b){
    return *(int*)a-*(int*)b;
}
/* quick sort */
void quick(int *arr,int start,int ending,int (*cmp)(void*,void*)){
    if(start>=ending) return;
    int pivot = random(arr,start,ending);
    quick(arr,start,pivot-1,cmp);
    quick(arr,pivot+1,ending,cmp);
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
void myswap(int *a, int *b){
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
/* Reverse array */
void reverseArr(int *arr, int n){
    for(int i=0;i<n/2;i++){
        int t = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = t;
    }
}
