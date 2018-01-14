#include<stdio.h>
#include<string.h>
int main(){
    char str[200],c;
    int i,length,counter=1;
    while(scanf("%s",str)!=EOF){
        length=strlen(str);
        c=str[0];
        for(i=0;i<=length;i++){
            if(str[i+1]!=c){
                if(c!='\0')
                    printf("%d%c",counter,c);
                c=str[i+1];
                counter=1;
            }
            else
                counter++;
        }
        printf("\n");
    }
    return 0;
}
