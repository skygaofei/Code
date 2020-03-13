// [USACO08OCT]牛骨头Bovine Bones.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<algorithm>
using namespace std;
int f[20010];
int main()
{
	int n=0;
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for(int i=1;i<=s1;i++)
		for(int j=1;j<=s2;j++)
			for (int z = 1; z <= s3; z++)
			{
				f[i + j + z]++;
				n = max(n, i + j + z);
			}
	int maxx = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (f[i] > maxx)
		{
			maxx = f[i];
			ans = i;
		}
	}
	cout << ans;
    return 0;
}

