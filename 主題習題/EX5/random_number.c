#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NCASE 30
#define N 10000
#define RANGE 1000000
#define THROWDICE ((rand() % RANGE) * (rand() % RANGE)) % RANGE
int main(void){
    srand(time(NULL));
    FILE *file;
    file = fopen("int_random.in","w");
    int i,j;
    fprintf(file,"%d\n",NCASE);
    for(i=0;i<NCASE;i++){
        int n=rand()*NCASE%N;
        fprintf(file,"%d\n",n);
        for(j=0;j<n-1;j++) fprintf(file,"%d ",THROWDICE);
        fprintf(file,"%d",THROWDICE);
        if(i!=NCASE-1) fprintf(file,"\n");
    }
    fclose(file);
    return 0;
}
