#include<bits/stdc++.h>
using namespace std;
int main()
{
	int sum=0;
	queue<int> s;
	int m,n;
	cin>>m>>n;
	int i;
	for(i=1;i<=m;i++)
	{
		s.push(i);
	}
	while(!s.empty())
	{
		sum++;
		if(sum==n)
		{
			sum=0;
			cout<<s.front()<<' ';
			s.pop();
			continue;
		}
		s.push(s.front());
		s.pop();
	}
	return 0;
}

