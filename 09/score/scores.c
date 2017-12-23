#include<stdio.h>
float f(float);

int main(){
    int T;
    freopen("score.in","r",stdin);
    //freopen("score.txt","w",stdout);
    scanf("%d",&T);
    while(T--){
        int K,N;
        scanf("%d%d",&N,&K);
        int score[N][4],i,j,k,w=0;
        float average[3]={0};

        for(i=0;i<N;i++){
            for(j=0;j<3;j++) scanf("%d",&score[i][j]);
            score[i][j]=0;      //initial
        }
        for(i=0;i<N;i++)
            for(j=0;j<3;j++) {
                score[i][3]+=score[i][j]; //sum
                average[j]+=score[i][j];
            }
        for(i=0;i<3;i++) average[i]/=N;
        /*sort*/
        for(i=0;i<N-1;i++)
            for(j=i+1;j<N;j++)
            if(score[i][3]<score[j][3])
                for(k=0;k<4;k++){
                    int t=score[i][k];
                    score[i][k]=score[j][k];
                    score[j][k]=t;
                }

        while(K--){
            for(i=0;i<3;i++)
                printf("%d ",score[w][i]);
            printf("%d\n",score[w++][i]);
        }
        for(i=0;i<2;i++)
            printf("%.2f ",f(average[i]));
        printf("%.2f\n",f(average[i]));
        if(T) printf("\n");
    }
    return 0;
}

float f(float a){
    a*=1000;
    a=(int)a;
    if((int)a%10>=5)a+=10;
    a=(int)a/10;
    return a/100;
}
