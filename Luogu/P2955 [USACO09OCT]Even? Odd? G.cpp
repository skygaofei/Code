#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(int(s[s.length()-1]-'0')%2==0)
			cout<<"even"<<endl;
		else
			cout<<"odd"<<endl;
	}
	return 0;
}