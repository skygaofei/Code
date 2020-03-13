#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define maxn 500005
#define re register
using namespace std;
inline int lowbit(int x){return x&(-x);}
int n,t[maxn],book[maxn];
long long result;
struct Node
{
    int val,pos;
}a[maxn];
bool cmp(Node a,Node b)
{
    if(a.val==b.val)
        return a.pos<b.pos;
    return a.val<b.val;
}
inline void add(int x)
{
    for(;x<=n;x+=lowbit(x))
        t[x]++;
}
inline int Query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=t[x];
    return res;
}
int main()
{
    scanf("%d",&n);
    for(register int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].val);
        a[i].pos=i;
    }
    sort(a + 1, a + n + 1, cmp);
    for(re int i=1;i<=n;++i)
        book[a[i].pos]=i;
    for(register int i=1;i<=n;i++)
    {
        add(book[i]);
        result+= i-Query(book[i]);
    }
    printf("%lld",result);
    return 0;
}