#include <cctype>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
inline void write(int x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
int main() 
{
	int ans=0;
	int n1=read(),n2=read();
	ans=n2-n1+1;
	for(int i=n1;i<=n2;i++)
		if((i-2)%4==0)
			ans--;
	printf("%d",ans);	
	return 0;
}