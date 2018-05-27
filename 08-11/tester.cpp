#include<bits/stdc++.h>
using namespace std;
/* String Secret */
char strtrans(char c){
    if(c>='a' && c<='z') return 'Z'-c+'a';
    if(c>='A' && c<='Z') return 'z'-c+'A';
    if(c>='0' && c<='8') return c+1;
    if(c == '9') return '0';
    return c;
}
/* Triangle */
void triangle(int n){
    int *leng = (int*) malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) cin>>leng[i];
    int ans = 0;
    sort(leng,leng+n);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                if(leng[i]+leng[j]>leng[k]) ans++;
    cout<<ans<<endl;
}
/* DeadLine */
struct DL{
    int dline,work;
};
bool dl_cmp(DL a,DL b){
    if(a.dline != b.dline) return a.dline<b.dline;
    return a.work<b.work;
}
void deadline(){
    int n,timepass=0;
    bool able = true;
    cin>>n;
    DL *dl = (DL*) malloc(sizeof(DL)*n);
    for(int i=0;i<n;i++) cin>>dl[i].work;
    for(int i=0;i<n;i++) cin>>dl[i].dline;
    sort(dl,dl+n,dl_cmp);
    for(int i=0;i<n;i++){
        timepass += dl[i].work;
        if(timepass>dl[i].dline){
            able = false;
            break;
        }
    }
    if(able) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

/* Schedule */
void schedule(){
    int work,machine;
    priority_queue<int> pq;
    cin>>work>>machine;
    for(int i=0;i<machine;i++) pq.push(0);
    for(int i=0;i<work;i++){
        int time,t=pq.top();
        pq.pop();
        cin>>time;
        pq.push(t-time);
    }
    for(int i=0;i<work-1;i++) pq.pop();
    cout<<-pq.top()<<endl;
}
/* Treasure */
void treasure(int n,int m,int t){
    const int N = 50000,M=100000;
    vector<int> v[M];
    queue<int> q;
    int start[N],val[N],ans=0;
    bool visit[N];
    for(int i=0;i<t;i++) cin>>start[i];
    for(int i=0;i<n;i++){
        cin>>val[i];
        visit[i]=false;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i=0;i<t;i++){
        int t = start[i];
        if(visit[t]) continue;
        visit[t] = true;
        q.push(t);
        while(!q.empty()){
            int f = q.front();
            q.pop();
            if(val[f]>ans) ans = val[f];
            for(int a:v[f]){
                if(!visit[a]){
                    q.push(a);
                    visit[a]=true;
                }
            }
        }
    }
    cout<<ans<<endl;
}
/* FCFS */
int calc(int job,int dline,int *time){
    priority_queue<int> pq;
    for(int i=0;i<dline;i++) pq.push(0);
    for(int i=0;i<job;i++){
        int f = pq.top();
        pq.pop();
        pq.push(f-time[i]);
    }
    for(int i=0;i<dline-1;i++) pq.pop();
    return -pq.top();
}
void fcfs(){
    int job,dline,maxtime=0,sum=0;
    cin>>job>>dline;
    int *time = (int*) malloc(sizeof(int)*job);
    for(int i=0;i<job;i++){
        cin>>time[i];
        sum+=time[i];
        if(maxtime<time[i]) maxtime=time[i];
    }
    if(maxtime>dline){
        cout<<"-1"<<endl;
        return ;
    }
    int up=job,down=sum/dline;
    while(up>down){
        int x = (up+down)/2;
        int res = calc(job,x,time);
        if(res<=dline) up=x;
        else down=x+1;
    }
    cout<<up<<endl;
}
/* tile */
struct T{
    int len,wid;
};
bool tile_cmp(T a,T b){
    if(a.wid == b.wid) return a.len>b.len;
    return a.wid>b.wid;
}
void tile(){
    int n;
    cin>>n;
    T *t = (T*)malloc(sizeof(T)*2*n);
    for(int i=0;i<n;i++) cin>>t[i].len>>t[i].wid;
    for(int i=0;i<n;i++){
        t[n+i].wid = t[i].len;
        t[n+i].len = t[i].wid;
    }
    sort(t,t+2*n,tile_cmp);
    int h=t[0].len,w=t[0].wid;
    for(int i=1;i<2*n;i++){
        if(t[i].wid == w) continue;
        h += t[i].len;
        w = t[i].wid;
    }
    cout<<h<<endl;
}
/* Spy */
void spy(){
    int spies,ans=0;
    cin>>spies;
    int *t = (int*) malloc(sizeof(int)*spies);
    bool *mark = (bool*) malloc(sizeof(bool)*spies);
    for(int i=0;i<spies;i++) mark[i]=false;
    for(int i=1;i<spies;i++) cin>>t[i];
    for(int i=spies-1;i>0;i--){
        if(!mark[i]) mark[t[i]]=true;
        else ans++;
    }
    if(mark[0]) ans++;
    cout<<ans<<endl;
}
/* Maximum component */
#define N 50000
#define M 1000000
vector<int> v[N];
int node[N];
bool visit[N];
int bfs(int a){
    queue<int> q;
    int t = node[a];
    q.push(a);
    visit[a]=true;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(int b:v[f]){
            if(visit[b]) continue;
            q.push(b);
            visit[b]=true;
            t+=node[b];
        }
    }
    return t;
}
void mcom(){
    int n,e,ans=0;
    cin>>n>>e;
    for(int i=0;i<n;i++){
        cin>>node[i];
        visit[i]=false;
        v[i].clear();
    }
    for(int i=0;i<e;i++){
        int a,b;
        scanf("%d%d",&a,&b);    // use scanf can be less time
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(visit[i]) continue;
        int f = bfs(i);
        if(ans<f) ans=f;
    }
    cout<<ans<<endl;
}
/* Line segment*/
struct LINE{
    int l,r;
};
bool line_cmp(LINE a,LINE b){
    return a.l<b.l;
}
void ls(){
    int n;
    cin>>n;
    LINE l[n];
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        l[i].l = min(a,b);
        l[i].r = max(a,b);
    }
    sort(l,l+n,line_cmp);
    int x = l[0].l,y=l[0].r,ans=0;
    for(int i=1;i<n;i++){
        if(l[i].l>y){
            ans += y-x;
            x = l[i].l;
            y = l[i].r;
        }
        else if(l[i].r>y) y=l[i].r;
    }
    ans += y-x;
    cout<<ans<<endl;
}
/* Spaceship */
void spaceship(int n){
    const int init = 1000;
    int *k1 = (int*) malloc(sizeof(int)*n);
    int *k2 = (int*) malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) cin>>k1[i]>>k2[i];
    int min1 = abs(init-k1[0]),min2 = abs(init-k2[0]);
    for(int i=1;i<n;i++){
        int a=min1+abs(k1[i]-k1[i-1]),b=min2+abs(k1[i]-k2[i-1]);
        int c=min1+abs(k2[i]-k1[i-1]),d=min2+abs(k2[i]-k2[i-1]);
        min1 = min(a,b);
        min2 = min(c,d);
    }
    cout<<min(min1,min2)<<endl;
}
/* independence on path*/
void iop(int n){
    int max1=0,max2=0;
    for(int i=0;i<n;i++){
        int a,tmp1,tmp2;
        cin>>a;
        tmp1 = max2 + a;
        tmp2 = max(max1,max2);
        max1 = tmp1;
        max2 = tmp2;
    }
    cout<<max(max1,max2)<<endl;
}
/* Babysitter */
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int main(void){
    const int STRSZE = 20,N=100;
    char str[STRSZE];
    pair<int,int> bs[N];
    int ncase;
    scanf("%d",&ncase);
    getchar(); gets(str);
    while(ncase--){
        int sze=0;
        gets(str);
        while(str[0]!=0){
            int a,b;
            sscanf(str,"%d %d",&a,&b);
            bs[sze].first = min(a,b);
            bs[sze++].second = max(a,b);
            if(gets(str) == NULL) break;
        }
        sort(bs,bs+sze,cmp);
        int n=0,r=-1,ans=0;
        while(n<200){
            for(int i=0;bs[i].first<=n;i++) if(bs[i].second>r) r=bs[i].second;
            n=r+1;
            ans++;
        }
        printf("%d",ans);
        if(ncase) printf("\n");
    }
    return 0;
}
/* LIS */
void lis(int m){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        vector<int>::iterator it = lower_bound(v.begin(),v.end(),a);
        if(it == v.end()) v.push_back(a);
        else *it = a;
    }
    cout<<v.size();
    if(m) cout<<endl;
}
int main(void){
    int n;
//    freopen("LIS.in","r",stdin);
    cin>>n;
//    while(n--) lis(n);
    return 0;
}
