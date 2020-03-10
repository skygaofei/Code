#include<bits/stdc++.h>
using namespace std;
int num[10010];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>num[i];
	for(int i=0;i<m;i++)
		next_permutation(num,num+n);
	for(int i=0;i<n;i++)
		cout<<num[i]<<' ';
	return 0;
} 