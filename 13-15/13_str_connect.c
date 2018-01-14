#include<stdio.h>
#include<string.h>
int main(){
    int n,n1,i,k1,k;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&n1);
        char str[n1][110];
        for(i=0;i<n1;i++) scanf("%s",str[i]);
        for(i=1;i<n1;i++){
            k1=0;
            k=1;
            while(k<=strlen(str[i])){
                if(strncmp(str[0]+(strlen(str[0])-k),str[i],k)==0) k1=k;
                k++;
            }
            strcat(str[0],str[i]+k1);
        }
        printf("%d\n%s\n",strlen(str[0]),str[0]);
    }
    return 0;
}
