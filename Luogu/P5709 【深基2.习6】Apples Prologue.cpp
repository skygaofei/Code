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
    int m,t,s;
    scanf("%d%d%d",&m,&t,&s);
    int ans=s/t+(s%t!=0);
    if(ans>m)
        printf("0");
    else
    printf("%d",m-ans);
	return 0;
}
