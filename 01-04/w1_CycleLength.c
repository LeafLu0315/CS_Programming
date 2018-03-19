#include<stdio.h>
#include<stdlib.h>
int main(){
    int p,q,i,*book;
    book=malloc(sizeof(int)*1000100);
    scanf("%d%d",&p,&q);
    while(q){
        for(i=0;i<q;i++) book[i]=0;
        for(i=1;;i++){
            if(book[p]) break;
            book[p]=i;
            p=(p*10)%q;
        }
        printf("%d\n",i-book[p]);
        scanf("%d%d",&p,&q);
    }
    return 0;
}
