// luogu-judger-enable-o2
#include<iostream>
using namespace std;
int s;
int main()
{
	int l, r;
	cin >> l >> r;
	for (int i = l; i <= r; i++)
	{
		if (i % 10 == 2)
			s++;
		if (i / 10 % 10 == 2)
			s++;
		if (i / 100 % 10 == 2)
			s++;
		if (i / 1000 % 10 == 2)
			s++;
		if (i / 10000 % 10 == 2)
			s++;
	}
	cout << s;
	return 0;
}