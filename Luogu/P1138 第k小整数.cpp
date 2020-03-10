// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int vis[30010];
int num[20010];
int n,k;
int nnum[20010];
int main()
{
	int s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++)
	{
		if(!vis[num[i]])
		{
			vis[num[i]]=1;
			s++;
			nnum[s]=num[i];
		}
	}
	if(k>s)
	{
		cout<<"NO RESULT";
		return 0;
	}
	cout<<nnum[k];
	return 0;
 } 