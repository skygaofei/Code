// pb的游戏.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		if (m % 2 == 1)
		{
			cout << "zs wins" << endl;
		}
		else
		{
			cout << "pb wins" << endl;
		}
	}
    return 0;
}

