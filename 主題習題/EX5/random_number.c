#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NCASE 10
#define N 10000
#define RANGE 100
#define THROWDICE ((rand() % RANGE) * (rand() % RANGE)) % RANGE
#define THROWALPHA rand()%26
int main(void){
    srand(time(NULL));
    FILE *file;
    file = fopen("intchar_random.in","w");
    int i,j;
    fprintf(file,"%d\n",NCASE);
    for(i=0;i<NCASE;i++){
        int n=rand()*NCASE%N;
        char c;
        fprintf(file,"%d\n",n);
        for(j=0;j<n-1;j++){
            c = THROWALPHA + ((rand()%2) ? 'A':'a');
            fprintf(file,"%d %c\n",THROWDICE,c);
        }
        c = THROWALPHA + ((rand()%2) ? 'A':'a');
        fprintf(file,"%d %c",THROWDICE,c);
        if(i!=NCASE-1) fprintf(file,"\n");
    }
    fclose(file);
    return 0;
}
