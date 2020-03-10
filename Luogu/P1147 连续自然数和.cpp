#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#define re register
using namespace std;
int m;
int main()
{
	scanf("%d",&m);
	for(re int i=m;i>=2;--i)
	{
		if(((m*2)%i==0&&m%i!=0)||(i&1&&m%i==0))
		{
			if(i&1&&i/2<=m/i)
				printf("%d %d\n",m/i-i/2,m/i+i/2);
			else if(!(i&1)&&(int)(m/i)+1>=i/2)
				printf("%d %d\n",(int)(m/i)-i/2+1,(int)(m/i)+i/2);
		}
	}	
	return 0;
}