// find x^n mod P
// y=x(mod P), m=n(mod P-1), ten sol=y^m (mod P)
#include <stdio.h>
typedef long long LL;
LL xyp(LL x,LL y,LL p) {
    int i;
    LL t,xi;
    t=1;xi=x;
    while (y>0) {
        if (y & 1) t=(t*xi)%p;
        y>>=1;
        xi=(xi*xi)%p;
    }
    return t;
}

int main()
{
	int i,j,k;
	long long m,y,p;
	char x[210],n[210];
	//freopen("power.in","r",stdin);
	//freopen("power.out","w",stdout);
	//freopen("test.in","r",stdin);
	//tt();
	while (scanf("%s%s%lld",x,n,&p)== 3) {
        //printf("%d, %d, %d\n", strlen(x),strlen(n),p);
        m=y=0;
        for (i=0; x[i] ; i++) {
            y=(y*10+x[i]-'0')%p;
        }
        for (i=0;n[i]; i++) m=(m*10+n[i]-'0')%(p-1);
        printf("%lld\n",xyp(y,m,p));
        //printf("%d\n",slow_inv(n,p));
	}
    return 0;
}
