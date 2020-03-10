#include<iostream>
#define mod 100003
int main()
{
	int s[100010] = { 0 }, n, k;
	std::cin >> n >> k;
	s[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k && (i - j) >= 0; j++)
			s[i] = s[i] + s[i - j];
		s[i] = s[i] % mod;
	}
	std::cout << s[n];
	return 0;

}