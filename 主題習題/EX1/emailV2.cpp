#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct EMAIL{
    char domain[100],username[100];
    char email[100];
};
int judge(EMAIL);
int exists(char [],char);
int duplicate(char [],char);
int nothing(char []);
bool ucmp(EMAIL,EMAIL);
bool dcmp(EMAIL,EMAIL);
int main(){
    int n,act,num=0,i;
    EMAIL e[100];
    freopen("email.in","r",stdin);
    scanf("%d\n",&n);
    while(n--){
        gets(e[num].email);
        puts(e[num].email);
        act=judge(e[num]);
        switch(act){
            case 0:
                cout<<"             =>is valid!"<<endl;
                break;
            case 1:
                cout<<"             =>missing \'@\'!"<<endl;
                break;
            case 2:
                cout<<"             =>missing \'.\'!"<<endl;
                break;
            case 3:
                cout<<"             =>duplicate \'@\'!"<<endl;
                break;
            case 4:
                cout<<"             =>dots are nearby!"<<endl;
                break;
            case 5:
                cout<<"             =>user name contains invalid character!"<<endl;
                break;
            case 6:
                cout<<"             =>domain contains invalid character!"<<endl;
                break;
            case 7:
                cout<<"             =>user name is empty!"<<endl;
                break;
            case 8:
                cout<<"             =>nothing behind the dot!"<<endl;
                break;
        }
        num++;
    }
    sort(e,e+num,ucmp);
    cout<<"Sort by user name :"<<endl;
    for(i=0;i<num;i++) cout<<e[i].email<<endl;
    sort(e,e+num,dcmp);
    cout<<"Sort by domain :"<<endl;
    for(i=0;i<num;i++) cout<<e[i].email<<endl;
    return 0;
}

int judge(EMAIL e){
    /* Not Exists @ or .*/
    if(!exists(e.email,'@')) return 1;
    if(!exists(e.email,'.')) return 2;
    /* Duplicate @ or Dots are nearby*/
    if(duplicate(e.email,'@')) return 3;
    if(duplicate(e.email,'.')) return 4;
    int i,counter=0;
    char *tok=strtok(e.email,"@");
    /* Initialize */
    memset(e.domain,'\0',sizeof(e.domain));
    memset(e.username,'\0',sizeof(e.username));
    /* Take out Domain and the UserName*/
    while(tok!=NULL){
        if(counter++) strcpy(e.domain,tok);
        else strcpy(e.username,tok);
        tok=strtok(NULL,"@");
    }
    /* nothing behind dot*/
    if(nothing(e.email)) return 8;
    /* Invalid character */
    char valid[]=".@_ ";
    char *s;
    for(s=e.username;*s;s++) if(!isalnum(*s) && strchr(valid,*s) == NULL) return 5;
    for(s=e.domain;*s;s++) if(!isalnum(*s) && strchr(valid,*s) == NULL) return 6;
    /* Empty */
    if(!strcmp(e.domain,"")) return 7;
    return 0;
}

int exists(char email[],char c){
    for(int i=0;i<strlen(email);i++)
        if(email[i] == c) return 1;
    return 0;
}

int duplicate(char email[],char c){
    int i,counter=0;
    if(c == '.'){
        for(i=0;i<strlen(email)-1;i++)
            if(email[i] == email[i+1] && email[i] == '.')
                return 1;
    }
    else{
        for(i=0;i<strlen(email);i++) {
            if(email[i] == c) counter++;
            if(counter>1) return 1;
        }
    }
    return 0;
}

bool ucmp(EMAIL a,EMAIL b){
    return strcmp(a.username,b.username)<0;
}

bool dcmp(EMAIL a,EMAIL b){
    return strcmp(a.domain,b.domain)<0;
}

int nothing(char email[]){
    for(int i=0;i<strlen(email);i++)
        if(email[i] == '.' && email[i+1] == '\0') return 1;
    return 0;
}
