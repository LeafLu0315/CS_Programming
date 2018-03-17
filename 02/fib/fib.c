#include <stdio.h>
long long m[3][3]={{0,0,0},{1,0,0},{0,1,0}},v[3];
int n,p;
void xyp() {
    int i,j,y=n-3,k;
    long long t[3][3]={0},xi[3][3],s,t2[3][3];
    for (i=0;i<3;i++) t[i][i]=1;
    for (i=0;i<3;i++) for (j=0;j<3;j++) xi[i][j]=m[i][j];
    while (y>0) {
        if (y & 1) {
            for (i=0;i<3;i++) for (j=0;j<3;j++) {
                s=0;
                for (k=0;k<3;k++) s=(s+(t[i][k]*xi[k][j])%p)%p;
                t2[i][j]=s;
            }
            for (i=0;i<3;i++) for (j=0;j<3;j++) t[i][j]=t2[i][j];
        }
        y>>=1;
        for (i=0;i<3;i++) for (j=0;j<3;j++) {
            s=0;
            for (k=0;k<3;k++) s=(s+(xi[i][k]*xi[k][j])%p)%p;
            t2[i][j]=s;
        }
        for (i=0;i<3;i++) for (j=0;j<3;j++) xi[i][j]=t2[i][j];
    }
    s=(t[0][0]+t[0][1]+t[0][2])%p;
    printf("%d\n",(int)s);
    return;
}

int main() {
	freopen("fib.in","r",stdin);
	freopen("fib.out","w",stdout);
	while (scanf("%d%d%lld%lld%lld",&n,&p,&(m[0][0]),&(m[0][1]),&(m[0][2]))==5) {
        if (n<=3) printf("1\n");
        else {
            xyp();
        }
	}
    return 0;
}
