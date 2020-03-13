// 超级书架.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<algorithm>
using namespace std;
int a[200010];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, b;
	cin >> n >> b;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int i;
	int sum = 0;
	sort(a , a + n, cmp);
	for (i = 0; sum < b; i++)
	{
		sum += a[i];
	}
	cout << i;
    return 0;
}

