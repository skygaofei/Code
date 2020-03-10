#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define maxn 2005
#define re register
using namespace std;
int f[maxn][maxn];
char s1[maxn],s2[maxn];
int len1,len2,k;
void dp()
{
    for(re int i=1;i<=len1;++i)
        for(re int j=1;j<=len2;++j)
            f[i][j]=min(f[i-1][j]+k,min(f[i][j-1]+k,f[i-1][j-1]+abs((int)s1[i]-(int)s2[j])));
}
void init()
{
    for(re int i=1;i<=len1;++i)
        f[i][0]=f[i-1][0]+k;
    for(re int i=1;i<=len2;++i)
        f[0][i]=f[0][i-1]+k;
}
int main()
{
    scanf("%s%s",s1+1,s2+1);
    scanf("%d",&k);
    len1=strlen(s1+1);
    len2=strlen(s2+1);
    init(),dp();
    printf("%d",f[len1][len2]);
    return 0;
}