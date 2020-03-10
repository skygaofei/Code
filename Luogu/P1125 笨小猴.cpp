#include<bits/stdc++.h>
#include<string>
#include<cstring>
using namespace std;
bool zhishu(int s)
{
	if(s==1||s==0)
	{
		return false;
	 } 
	for(int i=2;i<=sqrt(s);i++)
	{
		if(s%i==0)
			return false;
	}
	return true;
} 
int a[27];
int main()//96
{
	string s;
	int max=-9999999,min=9999999;
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		a[int(s[i])-96]++;
	}
	for(int i=1;i<=26;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
		if(a[i]<min&&a[i]!=0)
		{
			min=a[i];
		}
	}
	if(zhishu(max-min))
	{
		cout<<"Lucky Word";
		cout<<endl;
		cout<<max-min;
	}
	else
	{
		cout<<"No Answer";
		cout<<endl;
		cout<<0;
	}
 	return 0;
}
