// luogu-judger-enable-o2
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char cc;inline void R_int(int &x){
    while(cc=getchar(),cc<'!');x=cc-48;
    while(cc=getchar(),cc>'!')x=x*10+cc-48;
}
const int mod=64123,maxn=2005;
int n,K,W,len=1,head[maxn],ans=0,f[maxn][maxn],tmp[maxn],size[maxn],num[maxn],c[maxn<<1];
bool b[maxn],vis[maxn<<1];
struct Tree {int to,next;}e[maxn<<1];
void Set(int prt,int son){
    e[++len].to=son,e[len].next=head[prt],head[prt]=len;
}
struct Node {int num,c,th;}a[maxn];
bool Cmpn(Node a,Node b){return a.num<b.num;}
bool Cmpc(Node a,Node b){return a.c==b.c?a.num<b.num:a.c<b.c;}
void Add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
#define to e[i].to
int Zero(int rt,int num){
    if(vis[num])return c[num];vis[num]=true;
    int &x=c[num];x=1;
    for(int i=head[rt];i;i=e[i].next)
        if(i^(num^1))x=x*1ll*(Zero(to,i)+1)%mod;
    return x;
}
void Dfs(int rt,int fa){
    for(int i=head[rt];i;i=e[i].next)
        if(to^fa)Dfs(to,rt),size[rt]+=size[to];
    num[rt]=min(size[rt],K);
    memset(f[rt],0,(K+1)<<2);
}
void Run(int rt,int fa){
    int i,k;f[rt][b[rt]]=1;
    for(i=head[rt];i;i=e[i].next)if(to^fa)
        if(!size[to]){
            int x=Zero(to,i)+1;
            for(k=num[rt];~k;k--)if(f[rt][k])f[rt][k]=f[rt][k]*1ll*x%mod;
        }
        else Run(to,rt);
    memcpy(tmp,f[fa],(num[fa]+1)<<2);
    for(k=0;k<=num[fa];k++)if(tmp[k])
        for(i=0;i<=num[rt]&&i+k<=num[fa];i++)if(f[rt][i])
            Add(f[fa][i+k],tmp[k]*1ll*f[rt][i]%mod);
}
void Ans(int RT){
    if(a[RT].th>n-K)return;int i;
    for(i=1;i<=n;i++)b[i]=size[i]=a[i].th>a[RT].th;
    Dfs(RT,0),Run(RT,0),Add(ans,f[RT][K]*1ll*a[RT].c%mod);
}
signed main(){
    R_int(n),R_int(K),R_int(W),K--;int i,x,y;
    for(i=1;i<=n;i++)R_int(a[i].c),a[i].num=i;
    sort(a+1,a+n+1,Cmpc);
    for(i=1;i<=n;i++)a[i].th=i;
    sort(a+1,a+n+1,Cmpn);
    for(i=1;i<n;i++)R_int(x),R_int(y),Set(x,y),Set(y,x);
    for(i=1;i<=n;i++)Ans(i);
    printf("%d\n",ans);
}
