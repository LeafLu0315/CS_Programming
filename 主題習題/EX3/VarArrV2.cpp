#include<cstdio>
#include<cstdlib>
#include<cstring>
enum SEX{male,female};
struct INFO{
    char name[16],gender[7];
    int age;
};
int getName(char [],INFO*,int);
int getAge(char [],INFO*,int,int);
void getSex(char [],INFO*,int,int);
int main(){
    int info_size=1,counter=0,nendpos,aendpos;
    char str[100];
    INFO *info = (INFO*) malloc(sizeof(INFO)*info_size);
    freopen("data.in","r",stdin);
    while(gets(str)!=NULL){
        if(counter == info_size){
            info_size *= 2;
            printf("stack/queue is full, system auto allocated double size %d\n",info_size);
            info = (INFO*) malloc(sizeof(INFO)*info_size);
        }
        nendpos = getName(str,info,counter);
        aendpos = getAge(str,info,counter,nendpos);
        getSex(str,info,counter,aendpos);
        counter++;
    }
    return 0;
}

int getName(char str[],INFO *info,int counter){
    char c = str[0];
    char tmpname[16];
    int i,j;
    for(i=1,j=0;i<strlen(str);i++,j++){
        if(str[i] == c) break;
        tmpname[j]=str[i];
    }
    tmpname[j] = '\0';
    strcpy(info[counter].name,tmpname);
    printf("Name : %s ",info[counter].name);
    return i;
}

int getAge(char str[], INFO *info, int counter, int endpos){
    int age=0,i,j;
    for(i=endpos,j=0;i<strlen(str);i++,j++){
        if(str[i]>='0' && str[i] <= '9') age+=(str[i]-'0');
        else if(age != 0) break;
        if(j > 0) age*=10;
    }
    info[counter].age = age/10;
    printf("Age : %d ",info[counter].age);
    return i;
}

void getSex(char str[], INFO *info, int counter,int endpos){
    for(int i=endpos;i<strlen(str);i++){
        if(str[i] == 'm' || str[i] == 'M'){
            strcpy(info[counter].gender,"male");
            break;
        }
        else if(str[i] == 'f' || str[i] == 'F'){
            strcpy(info[counter].gender,"female");
            break;
        }
    }
    printf("Gender : %s\n",info[counter].gender);
    return;
}
