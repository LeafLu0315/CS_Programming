#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<memory.h>
/* Functions */
void quick(void*,int,size_t,int(*cmp)(void*,void*));
void myswap(char*,char*,size_t);
void printArr(int*,int);
/* Read file */
void readFile();
/* Testing functions */
void testing_int(int);
void testing_struct_intint(int);
void testing_struct_intchar(int);
/* Compare functions */
int int_cmp_bs(void*,void*);
int int_cmp_sb(void*,void*);
int intint_cmp_bs(void*,void*);
int intint_cmp_sb(void*,void*);
int intchar_cmp_bs(void *a,void *b);
int intchar_cmp_sb(void *a,void *b);
/* Structures */
typedef struct INTINT{
    int a,b;
}II;
typedef struct INTCHAR{
    int a;
    char c;
}IC;
int main(void){
    /* Gives the random number based on computer's time*/
    srand(time(NULL));
    /*parameters: 0 = small to big ; 1= big to small
     *other parameter will not be sorting */
    testing_int(0);     //testing integer random numbers
    testing_struct_intint(1);   //testing int int structure
    testing_struct_intchar(0);  //testing int char structure
    /* Read File*/
    readFile();
    return 0;
}
/* quick sort function */
void quick(void *start,int n ,size_t st ,int (*cmp)(void*,void*)){
    if(n <= 1) return;    // when size <= 1 then don't do the sorting
    char *i,*pivot,*base=(char*)start;  //base will be the front of the sorting array
    pivot = base + (n-1)*st;    //first make the last one being pivot
    myswap(pivot,base + (rand()%n)*st,st);  // swapping random pivot and ending point
    char *np=base;
    for(i=base;i<pivot;i+=st) if(cmp(i,pivot)<=0){
        myswap(i,np,st);    //swap the position,which fulfills the compare function
        np+=st;
    }
    myswap(pivot,np,st);
    int target=(np-base)/st;    //the new range
    quick(base,target,st,cmp);  //left side
    quick(np+st,n-target-1,st,cmp); //right side
    return ;
}
void myswap(char *a,char *b,size_t st){
    if(a==b) return;    //if a memory is equal to b then return
    char *t=malloc(sizeof(char)*st);    //copy the memory
    memcpy(t,a,st);
    memcpy(a,b,st);
    memcpy(b,t,st);
    free(t);
    return;
}
/* This is for user's not file*/
void printArr(int *arr,int n){
    int i;
    for(i=0;i<n-1;i++) printf("%d ",arr[i]);
    printf("%d",arr[i]);
}
/* ALL compare functions bs:big to small sb:small to big*/
int int_cmp_sb(void *a,void *b){
    return *((int*)a)-*((int*)b);   //small to big
}

int int_cmp_bs(void *a,void *b){
    return *((int*)b)-*((int*)a);   //big to small
}

int intint_cmp_sb(void *a,void *b){
    II A = *(II*)a,B = *(II*)b;
    if(A.a == B.a) return (A.b - B.b);
    return (A.a - B.a);
}

int intint_cmp_bs(void *a,void *b){
    II A = *(II*)a,B = *(II*)b;
    if(A.a == B.a) return (B.b - A.b);
    return (B.a - A.a);
}
int intchar_cmp_sb(void *a,void *b){
    IC A = *(IC*)a,B = *(IC*)b;
    if(A.c != B.c) return A.c - B.c;
    return A.a - B.a;
}
int intchar_cmp_bs(void *a,void *b){
    IC A = *(IC*)a,B = *(IC*)b;
    if(A.c != B.c) return B.c-A.c;
    return B.a - A.a;
}
/* For all testing files */
void testing_int(int action){
    int ncase,n,i,*arr,counter=0;
    FILE *fin,*fout;
    /* Read the file in integer random numbers */
    fin = fopen("testing\\int_random.in","r");
    if(fin == NULL){
        printf("Did Not Find the file\n"); //file not found exception
        return;
    }
    fout = fopen("testing\\int_random.out","w");
    fscanf(fin,"%d",&ncase);
    while(ncase--){
        fprintf(fout,"=================>Case %d Start<=================\n",counter++);
        fscanf(fin,"%d",&n);
        arr = malloc(sizeof(int)*n);
        for(i=0;i<n;i++) fscanf(fin,"%d",&arr[i]);
        if(action) quick(arr,n,sizeof(int),int_cmp_bs); // cmp depends on the action
        else quick(arr,n,sizeof(int),int_cmp_sb);
        for(i=0;i<n-1;i++) fprintf(fout,"%d ",arr[i]);
        fprintf(fout,"%d",arr[i]);
        if(ncase) fprintf(fout,"\n");
    }
    free(arr);
}

void testing_struct_intint(int action){
    int ncase,n,i,counter=0;
    FILE *fin,*fout;
    II *arr;
    /* Read the file in integer and integer random numbers */
    fin = fopen("testing\\intint_random.in","r");
    if(fin == NULL){
        printf("Did Not Find the file\n");
        return;
    }
    fout = fopen("testing\\intint_random.out","w");
    fscanf(fin,"%d",&ncase);
    while(ncase--){
        fprintf(fout,"=================>Case %d Start<=================\n",counter++);
        fscanf(fin,"%d",&n);
        arr = malloc(sizeof(II)*n);
        for(i=0;i<n;i++) fscanf(fin,"%d %d",&arr[i].a,&arr[i].b);
        if(action) quick(arr,n,sizeof(II),intint_cmp_bs);
        else quick(arr,n,sizeof(II),intint_cmp_sb);
        for(i=0;i<n-1;i++) fprintf(fout,"%d %d\n",arr[i].a,arr[i].b);
        fprintf(fout,"%d %d",arr[i].a,arr[i].b);
        if(ncase) fprintf(fout,"\n");
    }
    free(arr);
}
void testing_struct_intchar(int action){
    int ncase,n,i,counter=0;
    FILE *fin,*fout;
    IC *arr;
    /* Read the file in integer and char random numbers */
    fin = fopen("testing\\intchar_random.in","r");
    if(fin == NULL){
        printf("Did Not Find the file\n");
        return;
    }
    fout = fopen("testing\\intchar_random.out","w");
    fscanf(fin,"%d",&ncase);
    while(ncase--){
        fprintf(fout,"=================>Case %d Start<=================\n",counter++);
        fscanf(fin,"%d",&n);
        arr = malloc(sizeof(II)*n);
        for(i=0;i<n;i++) fscanf(fin,"%d %c",&arr[i].a,&arr[i].c);
        if(action) quick(arr,n,sizeof(IC),intchar_cmp_bs);
        else quick(arr,n,sizeof(IC),intchar_cmp_sb);
        for(i=0;i<n-1;i++) fprintf(fout,"%d %c\n",arr[i].a,arr[i].c);
        fprintf(fout,"%d %c",arr[i].a,arr[i].c);
        if(ncase) fprintf(fout,"\n");
    }
    free(arr);
}

void readFile(){
    #ifndef N
    #define N 100
    #endif
    #ifndef FILENAME
    #define FILENAME "testing\\int_random.bin"
    #endif
    char str[N];
    FILE *fin;
    fin = fopen(FILENAME,"rb");
    while(1){
        if(feof(fin)) break;
        fgets(str,N,fin);
        printf("%s\n",str);
    }
    return ;
}
