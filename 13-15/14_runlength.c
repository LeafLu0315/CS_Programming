#include<stdio.h>
#include<string.h>
int main(){
    int t,i,j,k,l;
    char s[160];
    while(scanf("%s",s)!=EOF){
        for(i=0;i<strlen(s);i++){
            j=1;
            while(s[i]==s[i+1]){
                i++;
                j++;
            }
            printf("%d%c",j,s[i]);
        }
        printf("\n");
    }
    return 0;
}
