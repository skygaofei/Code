#include<cstdlib>
#include<iostream>
#include<ctime>
int a[1001],i,j,s;
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	int n; 
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>j;
		a[j]++;
	}
	for(i=1;i<=1000;i++)
		if(a[i]!=0)
			s++;
	cout<<s<<endl;
	for(i=1;i<=1000;i++)
		if(a[i]!=0)
			cout<<i<<' ';
	return 0;
}