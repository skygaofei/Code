#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#define re register
#define maxn 1
using namespace std;
long long k,n,ans;
stack<int> num;
int main()
{
	scanf("%d%d",&k,&n);
	while(n)
		num.push(n%2),n/=2;
	while(!num.empty())
		ans+=num.top()*pow(k,num.size()-1),num.pop();
	printf("%lld",ans);
	return 0;
 } 