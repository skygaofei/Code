// Theatre Square.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
using namespace std;
int main()
{
	long long n, m, a;
	cin >> n >> m >> a;
	if (n%a == 0 && m%a != 0)
		cout << (n / a) * (m / a + 1);
	else if (n%a != 0 && m%a == 0)
		cout << (n / a + 1) * (m / a);
	else if (n%a != 0 && m%a != 0)
		cout << (n / a + 1) * (m / a + 1);
	else
		cout << (n / a)*(m / a);
    return 0;
}

