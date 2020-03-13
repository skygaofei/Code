#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
#define maxn 10000005
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    long long ans=1;
    for(re int i=2;i<=n;++i)
        ans*=i;
    printf("%lld",ans);
    return 0;
}
