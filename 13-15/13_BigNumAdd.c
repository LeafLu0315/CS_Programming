#include<stdio.h>
#include<string.h>
#define STRLEN 40
int main(){
    int ncase,len1,len2,len3,i;
    char s1[STRLEN],s2[STRLEN],sum[STRLEN];
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%s%s",s1,s2);
        len1=strlen(s1);
        len2=strlen(s2);
        strrev(s1);
        strrev(s2);
        for(i=len1;i<STRLEN;i++) s1[i]='0';
        for(i=len2;i<STRLEN;i++) s2[i]='0';
        len3=(len2>len1) ? len2:len1;
        for(i=0;i<len3;i++) sum[i]=(s1[i]-'0')+(s2[i]-'0');
        sum[len3]=0;
        for(i=0;i<len3;i++){
            sum[i+1]+=sum[i]/10;
            sum[i]%=10;
        }
        if(sum[len3]) printf("%c",sum[len3]+'0');
        for(i=len3-1;i>=0;i--) printf("%c",sum[i]+'0');
        if(ncase) printf("\n");
    }
    return 0;
}
