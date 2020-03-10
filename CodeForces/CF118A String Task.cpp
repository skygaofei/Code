// String Task.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != 'A'&&a[i] != 'O'&&a[i] != 'Y'&&a[i] != 'E'&&a[i] != 'U'&&a[i] != 'I'&&a[i] != 'a'&&a[i] != 'o'&&a[i] != 'y'&&a[i] != 'e'&&a[i] != 'u'&&a[i] != 'i')
		{
			cout << '.';
			if (a[i] >= 'A'&&a[i] <= 'Z')
				cout << char(a[i] + 32);
			else
				cout << a[i];
		}

	}
    return 0;
}

