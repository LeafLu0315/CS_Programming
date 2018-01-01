#include<stdio.h>
#define NUMBERS 4
#define BUFFER_SIZE 100

void sep(int [],int);
int duplicate(int []);
int exists(int [],int,int);

int main(){
    int times,guess,ans,A,B,buff;
    int Garr[NUMBERS],Aarr[NUMBERS],flag[NUMBERS],GBuffer[BUFFER_SIZE];
    int i,j;
    scanf("%d",&times);
    while(times--){
        scanf("%d",&ans);
        for(i=0;i<BUFFER_SIZE;i++) GBuffer[i]=0;
        buff=0;
        while(1){
            scanf("%d",&guess);
            if(ans == guess) break;
            if(exists(GBuffer,guess,buff)){
                if(guess<1000) printf("0%d is already guessed.\n",guess);
                else printf("%d is already guessed.\n",guess);
                continue;
            }
            sep(Garr,guess);
            if(duplicate(Garr)){
                if(guess<1000) printf("0%d is an invalid guess.\n",guess);
                else printf("%d is an invalid guess.\n",guess);
                continue;
            }
            //Initialize
            A=B=0;
            for(i=0;i<NUMBERS;i++) flag[i]=1;
            GBuffer[buff++] = guess;
            sep(Aarr,ans);
            //A
            for(i=0;i<NUMBERS;i++)
                if(Aarr[i]==Garr[i]){
                    A++;
                    flag[i]=0;
                }
            //B
            for(i=0;i<NUMBERS;i++)
                for(j=0;j<NUMBERS;j++)
                    if( (Aarr[i] == Garr[j]) && (flag[i]) ){
                        B++;
                        flag[i]=0;
                    }
            printf("%dA%dB\n",A,B);
        }
        printf("4A0B\n");
        if(times) printf("\n");
    }
    return 0;
}

void sep(int arr[],int a){
    int index=NUMBERS-1;
    if(a<1000) arr[0]=0;
    while(a){
        arr[index--]=a%10;
        a/=10;
    }
    return ;
}

int exists(int arr[],int a,int size){
    int i;
    for(i=0;i<size;i++)
        if(arr[i]==a) return 1;
    return 0;
}

int duplicate(int arr[]){
    int i,num[10]={0};
    for(i=0;i<NUMBERS;i++) num[arr[i]]++;
    for(i=0;i<10;i++) if(num[i]>=2) return 1;
    return 0;
}
