#include<stdio.h>
#include<string.h>
void Gets(char []);
int main(){
    int times,temp;
    char str[2000],replacing[100],to[100];
    scanf("%d\n",&times);
    while(times--){
        Gets(str);
        Gets(replacing);
        Gets(to);
        temp=0;
        while(temp<strlen(str)){
            if(temp+strlen(replacing)<=strlen(str)){
                if(strncmp(str+temp,replacing,strlen(replacing))==0){
                    printf("%s",to);
                    temp+=strlen(replacing);
                }
                else
                    printf("%c",str[temp++]);
            }
            else
                printf("%c",str[temp++]);

        }
        printf("\n");
    }
    return 0;
}

void Gets(char str[]){
    char c;
    int index=0;
    scanf("%c",&c);
    while(c!='\n'){
        str[index++]=c;
        scanf("%c",&c);
    }
    str[index]='\0';
    return;
}
