// luogu-judger-enable-o2
#include<iostream>
using namespace std;
bool flag = false;
int main()
{
	int mod;
	cin >> mod;
	for (int i = 10000; i <= 30000; i++)
	{
		if ((i / 100) % mod == 0 && ((i / 10) % 1000) % mod == 0 && (i % 1000) % mod == 0)
		{
			flag = true;
			cout << i << endl;
		}
	}
	if (flag == false)
		cout << "No";
	return 0;
}