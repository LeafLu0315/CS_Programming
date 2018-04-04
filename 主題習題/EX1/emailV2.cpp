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
int nothing(EMAIL);
int spacebetween(EMAIL);
bool dcmp(EMAIL,EMAIL);
bool ucmp(EMAIL,EMAIL);
int main(){
    int n,act,num=0,i,validnum=0;
    EMAIL e[100],valide[100];
    freopen("email.in","r",stdin);
    scanf("%d\n",&n);
    while(n--){
        gets(e[num].email);
        cout<<e[num].email;
        act=judge(e[num]);
        switch(act){
            case 0:
                cout<<" =>is valid!"<<endl;
                valide[validnum++]=e[num];
                break;
            case 1:
                cout<<" =>missing \'@\'!"<<endl;
                break;
            case 2:
                cout<<" =>missing \'.\'!"<<endl;
                break;
            case 3:
                cout<<" =>duplicate \'@\'!"<<endl;
                break;
            case 4:
                cout<<" =>dots are nearby!"<<endl;
                break;
            case 5:
                cout<<" =>user name contains invalid character!"<<endl;
                break;
            case 6:
                cout<<" =>domain contains invalid character!"<<endl;
                break;
            case 7:
                cout<<" =>user name is empty!"<<endl;
                break;
            case 8:
                cout<<" =>nothing behind the dot!"<<endl;
                break;
            case 9:
                cout<<" =>there is space between the words!"<<endl;
                break;
        }
        num++;
    }
    puts("=============================================");
    cout<<"Sort by user name :"<<endl;
    sort(valide,valide+validnum,ucmp);
    for(i=0;i<validnum;i++) cout<<valide[i].email<<endl;
    puts("=============================================");
    cout<<"Sort by domain :"<<endl;
    sort(valide,valide+validnum,dcmp);
    for(i=0;i<validnum;i++) cout<<valide[i].email<<endl;
    puts("=============================================");
    return 0;
}

int judge(EMAIL e){
    /* Not Exists @ or .*/
    if(!exists(e.email,'@')) return 1;
    if(!exists(e.email,'.')) return 2;
    /* Duplicate @ or Dots are nearby*/
    if(duplicate(e.email,'@')) return 3;
    if(duplicate(e.email,'.')) return 4;
    /* Initialize */
    int i,counter=0;
    char *tok=strtok(e.email,"@");
    memset(e.domain,'\0',sizeof(e.domain));
    memset(e.username,'\0',sizeof(e.username));
    /* Take out Domain and the UserName*/
    while(tok!=NULL){
        if(counter++) strcpy(e.domain,tok);
        else strcpy(e.username,tok);
        tok=strtok(NULL,"@");
    }
    /* Invalid character */
    char valid[]=".@_ ";
    char *s;
    for(s=e.username;*s;s++) if(!isalnum(*s) && strchr(valid,*s) == NULL) return 5;
    for(s=e.domain;*s;s++) if(!isalnum(*s) && strchr(valid,*s) == NULL) return 6;
    /* Empty */
    if(!strcmp(e.domain,"")) return 7;
    /* Nothing behind the dot*/
    if(nothing(e)) return 8;
    if(spacebetween(e)) return 9;
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


int nothing(EMAIL e){
    int dlen=strlen(e.domain)-1,ulen=strlen(e.username)-1;
    if(e.domain[dlen] == '.' || e.username[ulen] == '.') return 1;
    return 0;
}

int spacebetween(EMAIL e){
    for(int i=0;i<strlen(e.domain)-1;i++) if(e.domain[i] == ' ') return 1;
    for(int i=0;i<strlen(e.username)-1;i++) if(e.username[i] == ' ') return 2;
    return 0;
}

bool dcmp(EMAIL a,EMAIL b){
    return strcmp(a.domain,b.domain)<0;
}

bool ucmp(EMAIL a,EMAIL b){
    return strcmp(a.username,b.username)<0;
}

