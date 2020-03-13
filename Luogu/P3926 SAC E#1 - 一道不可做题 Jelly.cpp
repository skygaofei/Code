#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main() 
{
	long long a, c, p, q, r, x, t;
	scanf("%lld%lld%lld%lld%lld%lld", &a, &c, &p, &q, &r, &x);
	if (a<c) 
	{
		t = min(x, p*(c - a));
		x = x - t;
		a = a + t / p;
	}
	if (a == c)
		x = x - min(x, q);
	a = a + x / r;
	printf("%lld", a);
	return 0;
}