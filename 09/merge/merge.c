#include<stdio.h>

int main(){
    int T,NA,NB;
//    freopen("merge.in","r",stdin);
//    freopen("merge.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&NA,&NB);
        int Aarr[NA],Barr[NB],Merge[NA+NB],i,counter=0;
        for(i=0;i<NA;i++) scanf("%d",Aarr+i);
        for(i=0;i<NB;i++) scanf("%d",Barr+i);
        int a=0,b=0;
        for(i=0;i<NA+NB;i++){
            if(a<NA && b<NB){
                if(Aarr[a]>Barr[b]){
                    Merge[i]=Barr[b++];
                    counter++;
                }
                else {
                    Merge[i]=Aarr[a++];
                    counter++;
                }
            }
            else{
                if(a>=NA && b<NB) Merge[i]=Barr[b++];
                if(b>=NB && a<NA) Merge[i]=Aarr[a++];
            }
        }
        printf("%d\n",counter);
        if(NA+NB<=6){
            for(i=0;i<NA+NB-1;i++) printf("%d ",Merge[i]);
            printf("%d",Merge[i]);
        }
        else{
                for(i=0;i<3;i++) printf("%d ",Merge[i]);
                for(i=NA+NB-3;i<NA+NB-1;i++) printf("%d ",Merge[i]);
                printf("%d",Merge[i]);
        }
        printf("\n");
    }
    return 0;
}
