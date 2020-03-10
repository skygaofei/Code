// luogu-judger-enable-o2
// 联合权值.cpp: 定义控制台应用程序的入口点。
//
#include<cstdio>
#define maxnm 400010
using namespace std;
int point[maxnm], nex[maxnm], to[maxnm], w[maxnm], cnt, answer, max_answer;
void add(int x, int y)
{
	nex[++cnt] = point[x];
	to[cnt] = y;
	point[x] = cnt;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++)
	{
		int maxn = 0, maxm = 0;
		int pow1, pow2;
		pow1 = pow2 = 0;
		for (int j = point[i]; j; j = nex[j])
		{
			if (w[to[j]] > maxn)
			{
				maxm = maxn;
				maxn = w[to[j]];
			}
			else if (w[to[j]] > maxm)
				maxm = w[to[j]];
			pow1 = (pow1 + w[to[j]]) % 10007;
			pow2 = (pow2 + w[to[j]] * w[to[j]]) % 10007;
		}
		pow1 = (pow1*pow1) % 10007;
		answer = (answer + pow1 + 10007 - pow2) % 10007;
		if (max_answer < maxn*maxm)
			max_answer = maxn * maxm;
	}
	printf("%d %d", max_answer, answer);
	return 0;
}

