#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define re register
using namespace std;
int n;
int ans;
void dfs(int x)
{
	ans++;
	for(re int i=1;i<=x/2;++i)
		dfs(i);
}
int main()
{
	scanf("%d",&n);
	dfs(n);
	printf("%d",ans);
	return 0;
}
