#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<memory.h>
#define N 1000  //array size
#define GENERATE_RANGE 100000000   //random number range
/* functions */
int random(int*,int,int);
int cmp(void*,void*);
int cmp2(int,int);
void quick(int*,int,int,int (*cmp)(void*,void*));
void myswap(int*,int*);
void printArr(int*,int,bool);
void generateArr(int*,int);
int main(void){
    srand(time(NULL));
//    freopen("o.txt","w",stdout);
    int *arr = new int[N];
    generateArr(arr,N);
    quick(arr,0,N-1,cmp);
    bool rev = (cmp2(0,1)<0) ?  true:false;
    printArr(arr,N,rev);
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
int cmp2(int a,int b){
    return a-b;
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
