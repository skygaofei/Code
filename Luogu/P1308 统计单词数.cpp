#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
inline void work(string &x)
{
	for(int i=0;i<x.length();i++)
		if(x[i]>='A'&&x[i]<='Z')
			x[i]+=32;
}
int main()
{
//	freopen("tj.in","r",stdin);
//	freopen("tj.out","w",stdout);
	string a,b;
	cin>>a;
	work(a);
	cin.get();
	getline(cin,b);
	work(b);
	bool flag=false;
	int tim=0;
	int pos=b.find(a);
	if(pos==-1)
	{
		printf("-1");
		return 0;
	}
	int temp=pos;
	while(temp!=-1)
	{
		tim++;
		b.erase(temp,a.length());
		temp=b.find(a);
	}
	printf("%d %d",tim,pos);
	return 0;
}
