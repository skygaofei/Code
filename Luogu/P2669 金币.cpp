// luogu-judger-enable-o2
#include<iostream>
using namespace std;
int main()
{
	int k;
	cin >> k;
	int s = 1, sum = 0, p = 0, o = 0;
	while (p != k)
	{
		if (o == s)
		{
			s++;
			o = 0;
		}
		sum += s;
		p++;
		o++;
	}
	cout << sum;
	return 0;
}