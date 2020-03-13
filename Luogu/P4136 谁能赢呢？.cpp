#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#define re register
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			return 0;
		if(n&1)
			printf("Bob\n");
		else
			printf("Alice\n");
	}
	return 0;
}
