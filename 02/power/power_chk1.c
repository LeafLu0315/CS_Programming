// find x^n mod P
// y=x(mod P), m=n(mod P-1), ten sol=y^m (mod P)
#include <stdio.h>


int xyp(int x,int y,int p) {
    int i;
    long long t,xi;
    t=1;xi=x;
    while (y>0) {
        if (y & 1) t=(t*xi)%p;
        y>>=1;
        xi=(xi*xi)%p;
    }
    return (int)t;
}

int main()
{
	int i,j,p;
	long long m,y,k;
	char x[210],n[210];
	freopen("power.in","r",stdin);
	//freopen("power.out","w",stdout);
	//freopen("test.in","r",stdin);
	//tt();
	while (scanf("%lld%lld%d",&y,&m,&p)== 3) {
        //printf("%d, %d, %d\n", strlen(x),strlen(n),p);
        k=y;
        for (i=2;i<=m;i++) {k=(k*y)%p;}
        printf("%lld\n",k);
        //printf("%d\n",slow_inv(n,p));
	}
    return 0;
}
