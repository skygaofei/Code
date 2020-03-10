// 压缩技术.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
using namespace std;
int x = 1;
int n;
void print_0(int num)
{
	for (int i = 1; i <= num; i++)
	{
		if(x==n+1)
		{
			x = 1;
			cout << endl;
		}
		cout << 0;
		x++;
	}
}
void print_1(int num)
{
	for (int i = 1; i <= num; i++)
	{
		if (x == n + 1)
		{
			x = 1;
			cout << endl;
		}
		cout << 1;
		x++;
	}
}
int main()
{
	cin >> n;
	int s;
	bool flag = false;
	while (cin >> s)
	{
		if (!flag)
			print_0(s);
		else
			print_1(s);
		flag = !flag;
	}
    return 0;
}

