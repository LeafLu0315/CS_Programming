#include<stdio.h>
int gcd(int,int);

int main(){
    int times;
    freopen("math_fracAdd.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&times);
    while(times--){
        int a,b,c,d; //a/b + c/d
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int mol=(a*d)+(b*c),demol=b*d;
        int GCD=gcd(mol,demol);
        mol/=GCD;
        demol/=GCD;
        if(mol%demol==0) printf("%d\n",mol/demol);
        else if(mol<demol) printf("(%d/%d)\n",mol,demol);
        else{
            int integer=0;
            while(mol>demol){
                mol-=demol;
                integer++;
            }
            printf("%d+(%d/%d)\n",integer,mol,demol);
        }
    }
    return 0;
}

int gcd(int a,int b){
    int x=1;
    while(a !=0 && b != 0){
        if(a>b)
            a%=b;
        else
            b%=a;
        if(!a) x=b;
        if(!b) x=a;
    }
    return x;
}
