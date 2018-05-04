#include<cstdio>
#include<cstdlib>
#include<cstring>
enum SEX{male,female};
struct INFO{        //the structure of information
    char name[16],gender[7];
    int age;
};
/* Functions */
void getInformation(char [],INFO*,int);
int getName(char [],INFO*,int);
int getAge(char [],INFO*,int,int);
void getSex(char [],INFO*,int,int);

int main(){
    int info_size=1,counter=0;  //first allocate 1 size to info and data quantity is 0
    char str[100];
    INFO *info = (INFO*) malloc(sizeof(INFO)*info_size);
    while(gets(str)!=NULL){
        /* when the data quantity is equal to the malloc size then give double size */
        if(counter == info_size){
            info_size *= 2;
            printf("=======================================>queue/stack full, allocate double size %d\n",info_size);
            info = (INFO*) realloc(info,sizeof(INFO)*info_size);    //reallocate the double size
        }
        getInformation(str,info,counter++);   //get the information
    }
    free(info);
    return 0;
}
/* Get all information */
void getInformation(char str[],INFO *info,int counter){
    int nendpos,aendpos;
    nendpos = getName(str,info,counter);
    aendpos = getAge(str,info,counter,nendpos);
    getSex(str,info,counter,aendpos);
    return ;
}
/* Get the name with spaces*/
int getName(char str[],INFO *info,int counter){
    char c = str[0];    //This will get the first quotation mark
    char tmpname[16];   //This will deposit the name and then copy to the structure's name
    int i,j;
    for(i=1,j=0;i<strlen(str);i++,j++){
        if(str[i] == c) break;  //deposit the value until meets the another quotation mark
        tmpname[j]=str[i];
    }
    tmpname[j] = '\0';  //give the last place a end symbol
    strcpy(info[counter].name,tmpname); //Copy to structure's name
    printf("Name : %s ",info[counter].name);
    return i;   //Return the ending position
}

int getAge(char str[], INFO *info, int counter, int endpos){
    int age=0,i,j;
    for(i=endpos,j=0;i<strlen(str);i++){
        if(str[i]>='0' && str[i] <= '9'){
            if(j++ > 0) age *= 10;
            age+=(str[i]-'0'); //get the age
        }
        else if(age != 0) break;
    }
    info[counter].age = age;
    printf("Age : %d ",info[counter].age);
    return i;   //return the stopping position
}

void getSex(char str[], INFO *info, int counter,int endpos){
    //get the first character if m then male f then female
    for(int i=endpos;i<strlen(str);i++){
        if(str[i] == 'm' || str[i] == 'M'){
            strcpy(info[counter].gender,"male");
            break;
        }
        else if(str[i] == 'f' || str[i] == 'F'){
            strcpy(info[counter].gender,"female");
            break;
        }
        else strcpy(info[counter].gender,"UNDEFINED");
    }
    printf("Sex : %s\n",info[counter].gender);
    return;
}
