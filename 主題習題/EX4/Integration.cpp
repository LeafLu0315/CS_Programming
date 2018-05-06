#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
/* functions */
double integration(double(double),double,double,double);
double poly(double);
double mcalc(int,double,double,double);
void polyproc(char []);
double power(double,int);
const int cosize=10;
int coefficient[cosize];

int main(int argv, char* argc[]){
    /* give the maximum size */
    const int msize=13,polysize=50;
    char pol[polysize];
    /* cMath's functions*/
    const char math[msize][6]={"sin","cos","tan","asin","acos","atan","atan2","cosh","sinh","tanh","acosh","asinh","atanh"};
    /* Integrate from a to b and the width is t */
    double a,b,t,y=0;
    bool isMath;
    int i;
    /* Judge if it's from command line or execution file */
    if(argv > 0){
        while(scanf("%s%lf%lf%lf",pol,&a,&b,&t)!=EOF){
            /* The initial isMath will be false */
            isMath = false;
            for(i=0;i<msize;i++)
                if(!strcmp(math[i],pol)){   //if it compare to one of the cmath it will be true and record the position
                    isMath = true;
                    break;
                }
            if(isMath) y = mcalc(i,a,b,t);  //calculate the cmath's integration
            else{
                polyproc(pol);  //processing the polynomials
                y = integration(poly,a,b,t);    //calculate the integration
            }
            printf("%f\n",y);   //output the result
        }
    }
    else{   //CMD input
        isMath = false;
        sscanf(argc[i],"%s %lf %lf %lf",pol,&a,&b,&t);
        for(i=0;i<msize;i++)
            if(!strncmp(pol,math[i],sizeof(math[i])-1)){
                isMath = true;
                break;
            }
        if(isMath) y = mcalc(i,a,b,t);
        else{
            polyproc(pol);
            y = integration(poly,a,b,t);
        }
        printf("%f\n",y);
    }
    return 0;
}
/* find which function to use */
double mcalc(int pos,double a,double b,double t){
    double y = 0;
    switch(pos){
        case 0:
            y = integration(sin,a,b,t);
            break;
        case 1:
            y = integration(cos,a,b,t);
            break;
        case 2:
            y = integration(tan,a,b,t);
            break;
        case 3:
            y = integration(asin,a,b,t);
            break;
        case 4:
            y = integration(acos,a,b,t);
            break;
        case 5:
            y = integration(atan,a,b,t);
            break;
        case 7:
            y = integration(cosh,a,b,t);
            break;
        case 8:
            y = integration(sinh,a,b,t);
            break;
        case 9:
            y = integration(tanh,a,b,t);
            break;
        case 10:
            y = integration(acosh,a,b,t);
            break;
        case 11:
            y = integration(asinh,a,b,t);
            break;
        case 12:
            y = integration(atanh,a,b,t);
            break;
        default:
            break;
    }
    return y;
}
/* Calculate the sum */
double integration(double (*f)(double), double a, double b,double t){
    double sum=0;
    if(a<b) for(double i=a;i<=b;i+=t) sum += f(i);
    else for(double i=b;i<=a;i+=t) sum -= f(i);
    return sum*t;
}
/* Processing the polynomial */
void polyproc(char pol[]){
    const int tmpsize=5;
    int counter=0,num=0;
    int highest[tmpsize]={0};
    char tmp[tmpsize]={'\0'};
    bool execution_once,visits[tmpsize],isNegetive;
    for(int i=0;i<tmpsize;i++) visits[i] = false;
    for(int i=0;i<cosize;i++) coefficient[i] = 0;   //initialize
    if(isdigit(pol[0])) tmp[counter++] = pol[0];    //is digit or not
    for(int i=0;i<strlen(pol)-1;i++){
        if(pol[i] == '^' && isdigit(pol[i+1])) highest[pol[i+1]-'0']++; //Find the highest coefficient
        else if(isdigit(pol[i]) && pol[i+1] == 'x') highest[1]++;   //_x
    }
    if(isdigit(pol[strlen(pol)-1])) highest[0]++;   //normal number
    if(pol[0] == '-') isNegetive = true;
    if(isdigit(pol[0]) && pol[1] == 'x' && pol[2] == '^' && isdigit(pol[3])) coefficient[pol[3]-'0'] = pol[0]-'0';
    else if(isdigit(pol[0]) && pol[1] == 'x') coefficient[1] = pol[0]-'0';
    for(int i=1;i<=strlen(pol);i++){
        execution_once = false;
        if(i > 1) isNegetive = false;
        if(isdigit(pol[i]) && pol[i-1] == '-') isNegetive = true;
        if(isdigit(pol[i]) && pol[i+1] == 'x'){
            if(pol[i+2] == '^') coefficient[pol[i+3]-'0'] = pol[i]-'0';
            else coefficient[1] = pol[i]-'0';
        }
        if(isdigit(pol[i]) && pol[i-1] != '^') tmp[counter++] = pol[i]; //get the digit into the array
        else if(pol[i] == '+' || pol[i] == '-' || pol[i] == '\0'){
            for(int j = 0 ;j<counter;j++) {
                if(execution_once) num*=10;
                num += tmp[j]-'0';
                execution_once = true;
            }
            for(int i=tmpsize-1;i>=0;i--) if(highest[i] && !visits[i]){
                coefficient[i] = (num == 0) ? 1:num;
                if(isNegetive) coefficient[i] = -coefficient[i];
                visits[i] = true;
                break;
            }
            counter = num = 0;
        }
    }
    /* If the line is a normal number or one x */
    if(strlen(pol) == 1){
        if(pol[0] == 'x') coefficient[1]=1;
        else coefficient[0]=pol[0]-'0';
    }else if(strlen(pol) == 3 && pol[0]=='x' && pol[1] == '+' || pol[1] == '-' && isdigit(pol[2])){
        coefficient[0] = pol[2] - '0';
        coefficient[1] = 1;
    }
    for(int i=0;i<strlen(pol);i++) if(pol[i] == 'x' && pol[i+1]!='^'){
        if( (pol[i+1] == '+' || pol[i+1] == '-') && (pol[i-1] == '-' || pol[i-1] == '+')) coefficient[1]=1;
        else if(isdigit(pol[i-1])) coefficient[1] = pol[i-1]-'0';
    }
    return ;
}
/* calculate the f(x)*/
double poly(double x){
    double sum = 0;
    for(int i=0;i<5;i++) sum+=coefficient[i]*power(x,i);
    return sum;
}
/* power function*/
double power(double x, int y){
    double sum = 1,xi=x;
    while(y){
        if(y&1) sum*=xi;
        xi*=xi;
        y>>=1;
    }
    return sum;
}
