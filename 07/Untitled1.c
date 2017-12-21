#include<stdio.h>

int main(){
    int length,loop=0;
//    freopen("output.txt","w",stdout);
    while(1){
        scanf("%d",&length);
        if(!length) break;
        if(loop++>0) printf("\n");
        int Oarr[length],Earr[length],i,input;
        int odd=0,even=0;
        for(i=0;i<length;i++){
            scanf("%d",&input);
            if(input%2)
                Oarr[odd++]=input;
            else
                Earr[even++]=input;
        }
        if(odd){
            for(i=0;i<odd-1;i++)
                printf("%d ",Oarr[i]);
            printf("%d\n",Oarr[i]);
        }
        if(even){
            for(i=0;i<even-1;i++)
                printf("%d ",Earr[i]);
            printf("%d\n",Earr[i]);
        }
    }
    return 0;
}
