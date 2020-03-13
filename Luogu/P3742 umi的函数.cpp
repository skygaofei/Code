#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string x,y;
	cin>>x>>y;
	string ans="";
	char sum;
	if(x==y)
	{
		cout<<x;
		return 0;
	}
	for(int i=0;i<t;i++)
	{
		if(x[i]==y[i])
			sum=char(x[i]+1);
		else if(x[i]>y[i])
			sum=y[i];
		else if(x[i]<y[i])
		{
			cout<<-1;
			return 0;
		}
		if(sum>='a'&&sum<='z')
			ans+=sum;
		else
		{
			cout<<-1;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}