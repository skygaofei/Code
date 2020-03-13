// 进制转换.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<string>
using namespace std;
int num[1010];
int main()
{
	int b;
	cin >> b;
	string num1;
	cin >> num1;
	for (int i = 0; i < num1.length(); i++)
		num[i] = num1[i] - '0';
	int k = num1.length() - 1;
	int s = 0;
	cout << num[s] << '*' << b << '^' << k;
	s++;
	k--;
	while (k >= 0)
	{
		if (num[s] == 0)
		{
			k--;
			s++;
			continue;
		}
		cout << '+' << num[s] << '*' << b << '^' << k;
		k--;
		s++;
	}
    return 0;
}

