#include<stdio.h>
#ifndef FILENAME
#define FILENAME "int_random.bin"
#endif
#define N 100
int main(void){
    FILE *fin;
    char str[N];
    fin = fopen(FILENAME,"rb");
    while(1){
        if(feof(fin)) break;
        fgets(str,N,fin);
        printf("%s\n",str);
    }
    return 0;
}
