// 海关的船只.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<queue>
using namespace std;
struct que
{
	int t, x;
}p;
int sum[100010], ans=0;
int main()
{
	int n, x;
	cin >> n;
	queue<que> q;
	int k, t;
	for (int i = 1; i <= n; i++)
	{
		cin >> t >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> x;
			p.t = t;
			p.x = x;
			q.push(p);
			if (!sum[x])
				ans++;
			sum[x]++;
		}
		while ((!q.empty()) && t - q.front().t >= 86400)
		{
			sum[q.front().x]--;
			if (!sum[q.front().x])
				ans--;
			q.pop();
		}
		cout << ans << endl;
	}
    return 0;
}

