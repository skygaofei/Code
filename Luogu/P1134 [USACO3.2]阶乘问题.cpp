// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define R register
#define LL long long
#define U unsigned
using namespace std;
int main()
{
	R U LL n,ans=1;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		while(ans%10==0)
			ans/=10;
		ans%=1000000;
	}
	printf("%lld",ans%10);
	return 0;
}