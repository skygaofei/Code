#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
string s;
stack<int> num;
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> s;
	int temp;
	int t1, t2;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			temp = 0;
			while (s[i] >= '0'&&s[i] <= '9')
				temp = temp * 10 + (int)(s[i] - '0'), i++;
			num.push(temp);
		}
		if (s[i] == '+')
		{
			t1 = num.top();
			num.pop();
			t2 = num.top();
			num.pop();
			num.push(t1 + t2);
		}
		else if (s[i] == '-')
		{
			t1 = num.top();
			num.pop();
			t2 = num.top();
			num.pop();
			num.push(t2 - t1);
		}
		else if (s[i] == '*')
		{
			t1 = num.top();
			num.pop();
			t2 = num.top();
			num.pop();
			num.push(t1 * t2);
		}
		else if (s[i] == '/')
		{
			t1 = num.top();
			num.pop();
			t2 = num.top();
			num.pop();
			num.push(t2 / t1);
		}
	}
	cout << num.top();
	return 0;
}