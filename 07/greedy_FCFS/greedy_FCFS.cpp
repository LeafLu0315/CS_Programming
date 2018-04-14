#include<cstdio>
#include<cstdlib>
#include<queue>
#define N 100000
void sol();
int calc(int,int,int*);
int main(){
    int n;
    scanf("%d",&n);
    while(n--) sol();
    return 0;
}

void sol(){
    int dline,job,i,sum=0,mtime=0;
    int *t=(int*)malloc(sizeof(int)*N);
    scanf("%d%d",&job,&dline);
    for(i=0;i<job;i++){
        scanf("%d",&t[i]);
        sum+=t[i];
        if(mtime<t[i]) mtime=t[i];
    }
    if(dline<mtime){
        printf("-1\n");
        return ;
    }
    int down=sum/dline,up=job,r,res;
    while(up>down){
        r=(up+down)/2;
        res=calc(job,r,t);
        if(res<=dline) up=r;
        else down=r+1;
    }
    printf("%d\n",up);
    return ;
}

int calc(int job, int dline,int *t){
    std::priority_queue<int> pq;
    int i,res;
    for(i=0;i<dline;i++) pq.push(0);
    for(i=0;i<job;i++){
        res=pq.top();
        pq.pop();
        pq.push(res-t[i]);
    }
    for(i=0;i<dline-1;i++) pq.pop();
    res=-pq.top();
    pq.pop();
    return res;
}
