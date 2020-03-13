#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#define maxn 20005
#define re register
using namespace std;
int main()
{
	int a[4];
	scanf("%d%d%d",&a[1],&a[2],&a[3]);
	char s[10];
	scanf("%s",s);
	sort(a+1,a+4);
	for(re int i=0;i<3;++i)
		printf("%d",a[s[i]-'A'+1]),printf(" "); 
    return 0;
}
