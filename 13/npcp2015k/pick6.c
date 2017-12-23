#include<stdio.h>
#define MAX 1000000
int main(){
    int times,i,j,temp,y1,y2,last;
    int cpnumber1[10]={0},cpnumber2[10]={0};    //copy the numbers
    scanf("%d",&times);
    while(times--){
        int input,score1=0,score2=0;
        int number1[10]={0},number2[10]={0};    //input the number cards
        for(i=0;i<6;i++){
            scanf("%d",&input);
            number1[input]++;
        }
        for(i=0;i<6;i++){
            scanf("%d",&input);
            number2[input]++;
        }
        for(i=0;i<MAX;i++){
            temp=i;
            y1=1;
            y2=1;
            for(j=0;j<10;j++){
                cpnumber1[j]=number1[j];
                cpnumber2[j]=number2[j];
            }
            do{
                last=temp%10;
                if(cpnumber1[last]<1){      //didn't have card
                    y1=0;
                    break;
                }
                cpnumber1[last]--;
                temp/=10;
            }while(temp);
            temp=i;
            do{
                last=temp%10;
                if(cpnumber2[last]<1){
                    y2=0;
                    break;
                }
                cpnumber2[last]--;
                temp/=10;
            }while(temp);
            if(y1-y2==1) score1++;
            if(y2-y1==1) score2++;
        }
        printf("%d %d\n",score1,score2);
    }
    return 0;
}
