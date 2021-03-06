#include<cstdio>
#include<cstdlib>
#include<cstring>
enum SEX{male,female};
struct INFO{
    char name[16],gender[6];
    int age;
    SEX sex;
};
int main(){
    /* Variable declaration */
    freopen("data.in","r",stdin);
    char *str = (char *)malloc(sizeof(char)*100),*tok;
    int counter = 0, allocationSize = 1;
    bool takenName;
    INFO *info = (INFO*)malloc(sizeof(INFO)*allocationSize);
    /* Read the lines */
    while(gets(str)!=NULL){
        takenName = false;
        /* Auto allocation double size */
        if(counter >= allocationSize){
            allocationSize *= 2;
            printf("------------------------------->queue/stack full, allocate double size %d\n",allocationSize);
            info = (INFO*) malloc(sizeof(INFO)*allocationSize);
        }
        /* Taken the name including spaces */
        tok = strtok(str,"�g�h\"");
        while(tok!=NULL){
            if(!takenName){
                strcpy(info[counter].name,tok);
                takenName = true;
            }
            /* copy the rest part to str */
            else strcpy(str,tok);
            tok = strtok(NULL,"�g�h\"");
        }
        /* Scan the rest */
        sscanf(str,", %d, %s\n",&info[counter].age,info[counter].gender);
        /* If first word is m then will be male otherwise it will be female */
        if(info[counter].gender[0] == 'm' || info[counter].gender[0] == 'M') strcpy(info[counter].gender,"male");
        else strcpy(info[counter].gender,"female");
        /* Print out the result */
        printf("Name : %s, age : %d , gender : %s\n",info[counter].name,info[counter].age,info[counter].gender);
        counter++;
    }
    free(str);
    free(info);
    return 0;
}
