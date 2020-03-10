#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define re register
using namespace std;
struct Classmate
{
	int dis,num;
	string s;
}tmp;
vector<Classmate> v;
int main()
{
	int a,b;
	string c;
	while(cin>>a>>b>>c)
	{
		tmp.dis=b,tmp.num=a,tmp.s=c;
		v.push_back(tmp);
		if(c=="Moscow")
			break;
	}
	string ans1;
	int ans2=0x7fffffff;
	int x;
	for(re int i=v.size()-1;i>=0;--i)
	{
		x=0;
		for(re int j=0;j<v.size();++j)
			x+=abs(v[i].dis-v[j].dis)*v[j].num; 
		if(x<ans2)
			ans2=x,ans1=v[i].s;
	}
	cout<<ans1;
	printf(" %d",ans2);
	return 0;
}
