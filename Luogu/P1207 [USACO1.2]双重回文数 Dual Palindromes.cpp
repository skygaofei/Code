#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<sstream>
#include<iomanip>
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
	else if (j == 21)
	{
		cnt += "L";
	}
	else if (j == 22)
	{
		cnt += "M";
	}
	else if (j == 23)
	{
		cnt += "N";
	}
	else if (j == 24)
	{
		cnt += "O";
	}
	else if (j == 25)
	{
		cnt += "P";
	}
	else if (j == 26)
	{
		cnt += "Q";
	}
	else if (j == 27)
	{
		cnt += "R";
	}
	else if (j == 28)
	{
		cnt += "S";
	}
	else if (j == 29)
	{
		cnt += "T";
	}
	else if (j == 30)
	{
		cnt += "U";
	}
	else if (j == 31)
	{
		cnt += "V";
	}
	else if (j == 32)
	{
		cnt += "W";
	}
	else if (j == 33)
	{
		cnt += "X";
	}
	else if (j == 34)
	{
		cnt += "Y";
	}
	else if (j == 35)
	{
		cnt += "Z";
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
	int n, s;
	int count = 0, scount = 0;
	cin >> n >> s;
	scount = s + 1;
	while(count!=n)
	{
		cnt = "";
		int k = 0;
		string ans;

		for (int j = 2; j <= 10; j++)
		{
			cnt = "";
			ans = zh(scount, j);
			if (pd(ans))
				k++;
		}
		if (k >= 2)
		{
			cout << ans << endl;
			count++;
		}
		scount++;
	}
	return 0;
}