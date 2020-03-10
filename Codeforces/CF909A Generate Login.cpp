// Generate Login.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a1, a2;
	cin >> a1 >> a2;
	cout << a1[0];
	for (int i = 1; i < a1.length(); i++)
	{
		if (a1[i] < a2[0])
			cout << a1[i];
		else
			break;
	}
	cout << a2[0];
	return 0;
}

