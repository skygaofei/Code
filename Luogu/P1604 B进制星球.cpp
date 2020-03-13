#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int num1[2010], num2[2010], num3[2010];
int main()
{
	int k = 1;
	int B;
	cin >> B;
	string a, b;
	cin >> a >> b;
	int la = a.length(), lb = b.length();
	for (int i = la - 1; i >= 0; i--)
	{
		if (a[i] >= 'A'&&a[i] <= 'Z')
			num1[k] = a[i] - 55;
		else
			num1[k] = a[i] - '0';
		k++;
	}
	k = 1;
	for (int i = lb - 1; i >= 0; i--)
	{
		if (b[i] >= 'A'&&b[i] <= 'Z')
			num2[k] = b[i] - 55;
		else
			num2[k] = b[i] - '0';
		k++;
	}
	if (la < lb)
		la = lb;
	for (int i = 1; i <= la; i++)
		num3[i] = num1[i] + num2[i];
	for (int i = 1; i <= la; i++)
		if (num3[i] / B != 0)
		{
			num3[i + 1] += num3[i] / B;
			num3[i] %= B;
		}
	while (num3[la + 1] != 0)
		la++;
	for (int i = la; i >= 1; i--)
	{
		if (num3[i] >= 10)
			cout << char(num3[i] + 55);
		else
			cout << num3[i];
	}

	return 0;
}