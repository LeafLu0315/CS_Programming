#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<conio.h>
//define
#define N 4         // numbers
#define SZE 1000    //guess buffer size
#define RSZE 30
//Functions
void copy(int [],int []);
void judge(int,int);
void sep(int [],int);
void auto_guess(int);
void game_start();
int generate_ran();
int exists(int,int [],int);
int arr_to_int(int []);
int power(int,int);
int arr_size(int []);
int duplicate(int);
//Global variable
int A,B,guesstime;
int Aarr[N]={0},Garr[N]={0};

int main(){
    srand(time(NULL));
    int ans=0,guess,loop,ag,buff,i,tmp=0,d;
    int buffer[SZE];
    char c_ans[N+1];
    game_start();
    while(1){
        if(tmp++) printf("Input an action:\n");
        loop=1;
        scanf("%d",&d);
        switch(d){
            case 0:
                for(i=0;i<N;i++){
                    c_ans[i]=getch();
                    printf("*");
                }
                printf("\n");
                c_ans[i]='\0';
                printf("Starting to guess:\n");
                ans=atoi(c_ans);
                break;
            case 1:
                ans=rand()%10000;
                break;
            case 2:
                printf("Auto-guess mode can't have duplicate numbers!\n");
                printf("Input\n0:ans by user\n1:ans by random number\n");
                scanf("%d",&ag);
                if(ag == 0) {
                    while(1){
                        scanf("%d",&ans);
                        if(duplicate(ans)) printf("Please re-input\n");
                        if(!duplicate(ans)) break;
                    }
                }
                else if(ag == 1) {
                    ans=generate_ran();
                }
                else{
                    printf("ERROR ACTION !\n");
                    continue;
                }
                auto_guess(ans);
                loop=2;
                break;
            case 3:
                loop=0;
                break;
            default:
                printf("ERROR ACTION !\n");
                continue;
        }
        d=0;
        if(!loop) break;
        if(loop == 2) continue;
        //initialize
        for(i=0;i<SZE;i++) buffer[i]=-1;
        buff=0;
        while(1){
            scanf("%d",&guess);
            if(guess > 9999){
                printf("Please input lower than 10000\n");
                continue;
            }
            ++guesstime;
            if(exists(guess,buffer,buff)){
                printf("%d is already been guessed !\n",guess);
                continue;
            }
            A=B=0;
            if(ans == guess){
                printf("4A0B\n");
                break;
            }
            buffer[buff++]=guess;
            judge(ans,guess);
        }
        printf("You got it! (guessed %d times) !\n",guesstime);
    }
    printf("Thanks for playing\n");
    return 0;
}
//Copy array
void copy(int from[], int to[]){
    int i;
    for(i=0;i<N;i++) to[i]=from[i];
    return;
}
//Startup
void game_start(){
    printf("Welcome to the guessing game!\n");
    printf("Bulls(A) and Cows(B)\n");
    printf("There will be a 4-digit secret number.\nThen, in turn, the players try to guess their opponent's number who gives the number of matches. If the matching digits are in their right positions, they are \"bulls\", if in different positions, they are \"cows\"");
    printf("Input:\n0 Player gives an answer.\n1 Let computer gives an answer.\n2 Auto-guess.\n3 Quit.\n");
    return ;
}
//Judge guess
void judge(int ans, int guess){
    int i,j;
    int Aflag[N],Gflag[N];
    for(i=0;i<N;i++) Aflag[i]=Gflag[i]=1;
    for(i=0;i<N;i++) Aarr[i]=Garr[i]=0;
    sep(Aarr,ans); sep(Garr,guess);
    for(i=0;i<N;i++)
        if(Aarr[i] == Garr[i]){
            A++;
            Aflag[i]=Gflag[i]=0;
        }
    for(i=0;i<N;i++)
        for(j=0;j<N;j++){
            if(Aarr[i] == Garr[j] && Aflag[i] && Gflag[j]){
                B++;
                Gflag[j]=Aflag[i]=0;
            }
        }
    printf("->%dA%dB\n",A,B);
    return ;
}
//Separate int to array (if number < 1000 there will be 000x 00xx 0xxx)
void sep(int arr[], int a){
    int index=3;
    while(a){
        arr[index--]=a%10;
        a/=10;
    }
    return;
}
//If array exists the number a return 1(TRUE)
int exists(int a, int arr[], int size){
    int i;
    for(i=0;i<size;i++) if(arr[i] == a) return 1;
    return 0;
}
//auto-guess
void auto_guess(int ans){
    int guesstime=0,i,j,k,buff=0,size,bbuff=0;
    int arr[3]={1234,5678,9012},BBuffer[2*N],ABuffer[N]={0};
    int sepArr[N],Aflag[N],sepflag[N],BeingGuessed[SZE];
    srand(time(NULL));
    sep(Aarr,ans);
    printf("The answer is: ");
    for(i=0;i<N-1;i++) printf("%d",Aarr[i]);
    printf("%d\n",Aarr[i]);
    for(i=0;i<2*N;i++) BBuffer[i]=-1;
    for(i=0;i<N;i++) Aflag[i]=1;
    for(i=0;i<SZE;i++) BeingGuessed[i]=-1;
    for(i=0;i<3;i++){
        guesstime++;
        BeingGuessed[bbuff++]=arr[i];
        printf("Computer guess %d\n",arr[i]);
        if(arr[i] == ans){
            A=4;
            printf("4A0B\n");
            break;
        }
        A=B=0;
        sep(sepArr,arr[i]);
        //A
        for(j=0;j<N;j++){
            sepflag[j]=1;
            if(Aarr[j] == sepArr[j]){
                A++;
                Garr[j]=Aarr[j];
                sepflag[j]=Aflag[j]=0;
            }
        }
        for(j=0;j<N;j++) for(k=0;k<N;k++)
            if(Aarr[j] == sepArr[k] && Aflag[j] && sepflag[k]){
                B++;
                BBuffer[buff++]=Aarr[j];
            }
        printf("->%dA%dB\n",A,B);
    }
    while(1){
        A=B=0;
        if(arr_to_int(Garr)==ans) break;
        size=arr_size(BBuffer);
        for(i=0;i<N;i++){
            if(Aflag[i]){
                Garr[i]=BBuffer[rand()%size];
                if(Garr[i] == Aarr[i]) Aflag[i]=0;
            }
        }
        if(ans == arr_to_int(Garr)){
            guesstime++;
            printf("Computer guess %d\n->4A0B\n",ans);
            break;
        }
        if(exists(arr_to_int(Garr),BeingGuessed,bbuff) || duplicate(arr_to_int(Garr))) continue;
        BeingGuessed[bbuff++]=arr_to_int(Garr);
        printf("Computer guess ");
        guesstime++;
        for(i=0;i<N-1;i++) printf("%d",Garr[i]);
        printf("%d\n",Garr[i]);
        judge(ans,arr_to_int(Garr));
    }
    printf("Computer guessed %d times!\n",guesstime);
    return;

}
//Parse array to integer
int arr_to_int(int arr[]){
    int i,res=0;
    for(i=0;i<N;i++)
        res+=power(10,N-i-1) * arr[i];
    return res;
}
//Power function
int power(int x,int y){
    int res=1;
    while(y){
        if(y & 1) res*=x;
        x*=x;
        y>>=1;
    }
    return res;
}
//Find the array size
int arr_size(int arr[]){
    int i,res=0;
    for(i=0;i<N;i++) {
        if(arr[i] == -1) break;
        res++;
    }
    return res;
}
//duplicate
int duplicate(int a){
    int numb[10]={0},i;
    while(a){
        numb[a%10]++;
        a/=10;
    }
    for(i=0;i<10;i++) if(numb[i]>1) return 1;
    return 0;
}
//Generate not duplicate number
int generate_ran(){
    int i,j,arr[RSZE],res[N],index=N-1;
    srand(time(NULL));
    for(i=0;i<N;i++) res[i]=-1;
    for(i=0;i<RSZE;i++) arr[i]=rand()%10;
    for(i=0,j=0;i<N;j++) if(!exists(arr[j],res,N)) res[i++]=arr[j];
    return arr_to_int(res);
}
