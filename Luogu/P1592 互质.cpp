#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int a[1000005];
int kgcd(int a, int b)
{ 
    if (a == 0) return b; 
    if (b == 0) return a; 
    if (!(a & 1) && !(b & 1)) 
        return kgcd(a>>1, b>>1)<<1;
    else if (!(b & 1))
    return kgcd(a, b>>1); 
    else if (!(a & 1)) return kgcd(a>>1, b); 
    else return kgcd(abs(a - b), min(a, b)); 
} 
inline int read()
{
	int s=0,w=1;
   	char ch=getchar();
   	while(ch<='0'||ch>'9')
  	{
   		if(ch=='-')w=-1;
   		ch=getchar();
   	}
   	while(ch>='0'&&ch<='9') 
   		s=s*10+ch-'0',ch=getchar(); 
   	return s*w;
}
int main()
{
	int ans=0;
	int n,k;
	n=read();
	k=read();
	for(int i=1;i<n;i++)
		if(__gcd(i,n)==1)
			a[++ans]=i;
	printf("%d",(k-1)/ans*n+a[(k-1)%ans+1]);
	return 0;
}
