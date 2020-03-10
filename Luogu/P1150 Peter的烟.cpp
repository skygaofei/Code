// luogu-judger-enable-o2
#include<iostream>
using namespace std;
#define ll unsigned long long
ll n, k, ans;
ll l;
int main()
{
	cin >> n >> k;
	ans = n;
	while (n / k != 0)
	{
		ans += n / k;
		l += n % k;
		n = n / k;
	}
	l += n % k;
	cout << ans + l / k;
	return 0;
}