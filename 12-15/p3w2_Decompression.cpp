#include<bits/stdc++.h>
using namespace std;
#define N 10000

int main(void){
    char str[N];
    while(scanf("%s",&str)!=EOF){
        int num;
        char *ptr = str;
        char *ptr2 = ptr+1;
        while(*ptr2!='\0'){
            num = atoi(ptr);
            while(isalpha(*ptr2)) ptr2++;
            for(int i=0;i<num;i++) for(int j=1;j<ptr2-ptr;j++) printf("%c",*(ptr+j));
            ptr = ptr2++;
        }
        printf("\n");
        for(int i=0;i<N;i++) str[i]=0;
    }
    return 0;
}

