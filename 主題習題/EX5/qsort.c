#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<memory.h>
#define N 100
void quick(void*,int,size_t,int(*cmp)(void*,void*));
void myswap(char*,char*,size_t);
void printArr(int*,int);
void testing_int(int);
int int_cmp_bs(void*,void*);
int int_cmp_sb(void*,void*);
int main(void){
    srand(time(NULL));
    /*parameters: 0 = small to big ; 1= big to small
     *other parameter will not be sorting */
    testing_int(0);     //testing integer random numbers
    return 0;
}
void quick(void *start,int n ,size_t st ,int (*cmp)(void*,void*)){
    if(n<=1) return;    // when size <= 1 then don't do the sorting
    char *i,*pivot,*np,*base=(char*)start;
    pivot=base+(n-1)*st;
    myswap(pivot,base+(rand()%n)*st,st);  // swapping random pivot and ending point
    np=base;
    for(i=base;i<pivot;i+=st) if(cmp(i,pivot)<=0){
        myswap(i,np,st);
        np+=st;
    }
    myswap(pivot,np,st);
    int n1=(np-base)/st;
    quick(base,n1,st,cmp);
    quick(np+st,n-n1-1,st,cmp);
    return ;
}
void myswap(char *a,char *b,size_t st){
    if(a==b) return;
    char *t=malloc(sizeof(char)*st);
    memcpy(t,a,st);
    memcpy(a,b,st);
    memcpy(b,t,st);
    free(t);
    return;
}

void testing_int(int action){
    int ncase,n,i,*arr,counter=0;
    FILE *fin,*fout;
    /* Read the file in integer random numbers */
    fin = fopen("int_random.in","r");
    fout = fopen("int_random.out","w");
    fscanf(fin,"%d",&ncase);
    while(ncase--){
        fprintf(fout,"=================>Case %d Start<=================\n",counter++);
        fscanf(fin,"%d",&n);
        arr = malloc(sizeof(int)*n);
        for(i=0;i<n;i++) fscanf(fin,"%d",&arr[i]);
        if(action) quick(arr,n,sizeof(int),int_cmp_bs);
        else quick(arr,n,sizeof(int),int_cmp_sb);
        for(i=0;i<n-1;i++) fprintf(fout,"%d ",arr[i]);
        fprintf(fout,"%d",arr[i]);
        if(ncase) fprintf(fout,"\n");
    }
    free(arr);
}

void printArr(int *arr,int n){
    int i;
    for(i=0;i<n-1;i++) printf("%d ",arr[i]);
    printf("%d",arr[i]);
}

int int_cmp_sb(void *a,void *b){
    return *((int*)a)-*((int*)b);   //small to big
}

int int_cmp_bs(void *a,void *b){
    return *((int*)b)-*((int*)a);   //big to small
}
