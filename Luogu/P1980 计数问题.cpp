#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,s=0,i,j,h;
	cin>>n>>x;
	for(i=1;i<=n;i++)
	{
		h=i;
		while(h!=0)
		{
			j=h%10;
			if(x==j)
				s++;
			h=h/10;
		}
	}
	cout<<s;
	return 0;
}
