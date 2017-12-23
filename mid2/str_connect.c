#include<stdio.h>
#include<string.h>
#define SIZE 300
int main(){
    int strings,times,i,point;
    char str[SIZE],combine[SIZE];
    scanf("%d",&times);
    while(times--){
        scanf("%d",&strings);
        while(strings--){
            point=0;
            scanf("%s",str);
            for(i=0;i<strlen(str);i++)
                if(combine[point++]!=str[i]){
                    combine[point++]=str[i];
                    point=0;
                }
        }
        printf("\n");
    }
    return 0;
}
