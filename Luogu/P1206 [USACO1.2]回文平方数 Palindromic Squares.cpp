#include<iostream>
#include<string>
using namespace std;
string cnt;
string zh(int i, int n)
{
	long long j;
	j = i%n;
	i = i / n;
	if (i != 0)
		zh(i, n);
	if (j == 10)
	{
		cnt += "A";
	}
	else if (j == 11)
	{
		cnt += "B";
	}
	else if (j == 12)
	{
		cnt += "C";
	}
	else if (j == 13)
	{
		cnt += "D";
	}
	else if (j == 14)
	{
		cnt += "E";
	}
	else if (j == 15)
	{
		cnt += "F";
	}
	else if (j == 16)
	{
		cnt += "G";
	}
	else if (j == 17)
	{
		cnt += "H";
	}
	else if (j == 18)
	{
		cnt += "I";
	}
	else if (j == 19)
	{
		cnt += "J";
	}
	else if (j == 20)
	{
		cnt += "K";
	}
	else
		cnt += (char)(j + '0');
	return cnt;
}
bool pd(string ans)
{
	int l = ans.length() - 1;
	for (int i = 0, j = l; i <= l / 2; i++, j--)
		if (ans[i] != ans[j])
			return false;
	return true;
}
int main()
{
	string ans;
	int b;
	cin >> b;
	for (int i = 1; i <= 300; i++)
	{
		ans = "";
		cnt = "";
		ans += zh(i*i, b);
		if (pd(ans))
		{
			cnt = "";
			cout << zh(i,b) << ' ' << ans << endl;
		}
	}
	return 0;
}