#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
char a[10][10];
int main()
{
	scanf("%s%s%s", &a[1], &a[2], &a[3]);
	if (a[1][0] == a[3][2] && a[1][1] == a[3][1] && a[1][2] == a[3][0] && a[2][0] == a[2][2])
		printf("YES");
	else
		printf("NO");
	return 0;
}