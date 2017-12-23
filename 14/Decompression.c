#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char str[2000],num[100],eng[300];
    int i,counter=0,counter2=0,L,times;
    while(gets(str)!=NULL){
        L=strlen(str);
        for(i=0;i<L;i++){
            if(str[i]>='0' && str[i]<='9'){
                num[counter++]=str[i];
                num[counter]='\0';
            }
            else{
                eng[counter2++]=str[i];
                eng[counter2]='\0';
                if((str[i+1]>='0' && str[i+1]<='9') || (i==L-1)){
                    times=atoi(num);
                    while(times--) printf("%s",eng);
                    counter=counter2=0;
                }
            }

        }
        printf("\n");
    }
    return 0;
}
