#include<stdio.h>

int main(){
    int search,M;
    while(scanf("%d%d",&search,&M)!=EOF){
        int s[2]={0},num[7]={0},num_index=0,s_index=0;
        while(M){
            num[num_index++]=M%10;
            M/=10;
        }
        while(search){
            s[s_index++]=search%10;
            search/=10;
        }
        int counter=0,i,j;
        for(i=0;i<num_index-1;i++)
            if(num[i]==s[0] && num[i+1]==s[1])
                counter++;
        printf("%d\n",counter);
    }
    return 0;
}
