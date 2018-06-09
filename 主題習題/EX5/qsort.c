#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<memory.h>
#define N 100
void quick(void*,int,size_t,int(*cmp)(void*,void*));
void myswap(char*,char*,size_t);
void printArr(int*,int);
int int_cmp_bs(void*,void*);
int int_cmp_sb(void*,void*);
int main(void){
    srand(time(NULL));
    int ncase,n,i,*arr;
    freopen("random.in","r",stdin);
    freopen("o.txt","w",stdout);
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d",&n);
        arr = malloc(sizeof(int)*n);
        for(i=0;i<n;i++) scanf("%d",&arr[i]);
        quick(arr,n,sizeof(int),int_cmp_bs);
        printArr(arr,n);
        if(ncase) printf("\n");
    }
    free(arr);
    return 0;
}
void quick(void *start,int n ,size_t st ,int (*cmp)(void*,void*)){
    if(n<=1) return;
    char *i,*piv,*np,*base=(char*)start;
    piv=base+(n-1)*st;
    myswap(piv,base+(rand()%n)*st,st);
    np=base;
    for(i=base;i<piv;i+=st){
        if(cmp(i,piv)<=0){
            myswap(i,np,st);
            np+=st;
        }
    }
    myswap(piv,np,st);
    int n1=(np-base)/st;
    quick(base,n1,st,cmp);
    quick(np+st,n-n1-1,st,cmp);
}
void myswap(char *p,char *q,size_t st){
    if(p==q) return;
    char *t=malloc(sizeof(char)*st);
    memcpy(t,p,st);
    memcpy(p,q,st);
    memcpy(q,t,st);
    free(t);
    return;
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
