#include<cstdio>
#include<algorithm>
using namespace std;
int x[10001],y[10001];//苹果的高度和所需力气
int main()
{
    int n,s; scanf("%d %d",&n,&s);
    int a,b,m=0;
    scanf("%d %d",&a,&b);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        if(a+b<x[i]) y[i]=-1;
    sort(y+1,y+n+1);
    for(int i=1;i<=n;i++)
         if(y[i]!=-1)
         {
             s-=y[i]; 
             if(s>=0) m++;
             else break;
         }
    printf("%d",m);
    return 0;
}