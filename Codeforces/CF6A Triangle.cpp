#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int a[5];
	scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
	sort(a+1,a+5);
	if(a[1]+a[2]>a[3]||a[1]+a[2]>a[4]||a[1]+a[3]>a[4]||a[2]+a[3]>a[4])
		printf("TRIANGLE");
	else if(a[1]+a[2]==a[3]||a[1]+a[2]==a[4]||a[1]+a[3]==a[4]||a[2]+a[3]==a[4])
		printf("SEGMENT");
	else
		printf("IMPOSSIBLE");
	return 0;
}
