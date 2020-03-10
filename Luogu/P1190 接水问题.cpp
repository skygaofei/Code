#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<ctime>
#include<queue>
#include<sstream>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
int w[10100], wat[110]; queue<int> s; long long sum;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
	    int x;
	    cin>>x;
	    s.push(x);
	}
		//cin >> w[i];
	//sort(w + 1, w + n + 1,cmp);
	//for (int i = 1; i <= n; i++)
		//s.push(w[i]);
	for (int i = 1; i <= m; i++)
	{
		wat[i] = s.front();
		s.pop();
	}
		
	for (int i = 1; wat[1]!=0; i++)
	{
		sort(wat + 1, wat + m + 1,cmp);
		sum = sum + wat[m];
		for (int j = 1; j <= m; j++)
		{
			wat[j] = wat[j] - wat[m];
		}
		if (!s.empty())
		{
			wat[m] = s.front();
			s.pop();
		}
		else
		{
			m--;
		}
	}
	cout << sum;
	//fclose(stdin);
	//fclose(stdout);
	//system("pause");
	return 0;
}