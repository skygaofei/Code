#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ans=99999999;
	int n;
	cin>>n;
	for(int i=1;i<=3;i++)
	{
		int sum=0;
		int k,s;
		cin>>k>>s;
		while(sum<n)
			sum+=k;
		sum=(sum/k)*s;
		if(sum<=ans)
			ans=sum;
	}
	cout<<ans; 
	return 0;
}

