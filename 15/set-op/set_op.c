#include<stdio.h>
#include<string.h>
#define MAX 200
int exists(char [],char,int);
void sorting(char [],int);
int main(){
    int n,m,i,j,a,b,counter,counter2,t;
    char str[MAX][MAX],c,res[MAX],tmp[MAX];
    scanf("%d %d\n",&n,&m);
    for(i=0;i<n;i++) scanf("%s",str[i]);
    while(m--){
        scanf("%d %c %d",&a,&c,&b);
        counter2=counter=0;
        for(i=0;i<MAX;i++) res[i]=tmp[i]='\0';
        for(i=0;i<strlen(str[a]);i++) tmp[counter++]=str[a][i];
        t=counter;
        for(i=0;i<strlen(str[b]);i++) tmp[counter++]=str[b][i];
        switch(c){
            case '+':
                for(i=0;i<counter;i++) if(!exists(res,tmp[i],counter2)) res[counter2++]=tmp[i];
                sorting(res,counter2);
                printf("%s\n",res);
                break;
            case '*':
                for(i=0;i<t;i++)
                    for(j=t;j<counter;j++)
                        if(tmp[i]==tmp[j] && !exists(res,tmp[i],counter2)){
                            res[counter2++]=tmp[i];
                            break;
                        }
                sorting(res,counter2);
                if(strlen(res))printf("%s\n",res);
                else printf("-1\n");
                break;
            default:
                printf("ERROR OPERATOR\n");
        }

    }
    return 0;
}

int exists(char arr[],char c,int size){
    int i;
    for(i=0;i<size;i++) if(arr[i]==c) return 1;
    return 0;
}

void sorting(char arr[],int size){
    int i,j,t;
    for(i=0;i<size-1;i++)
        for(j=i+1;j<size;j++)
            if(arr[i]>arr[j]){
                t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
    return ;
}
