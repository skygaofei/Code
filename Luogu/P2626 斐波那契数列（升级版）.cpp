// luogu-judger-enable-o2
#include<iostream>
#include<cmath>
using namespace std;
int f[110];
void Analyse(int n)
{
	cout << n << "=";
	if (n == 2)
	{
		cout << n << endl;
	}
	else
	{
		for (int i = 2; i <= sqrt(static_cast<double>(n)); i++)
		{
			if (n % i == 0)
			{
				n = n / i;
				cout << i << "*"; 
				i--;
			}
		}
		cout << n << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		f[i] = (f[i - 1] + f[i - 2]) % 2147483648;
	}
	Analyse(f[n]);
	return 0;
}