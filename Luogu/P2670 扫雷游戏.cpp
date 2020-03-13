// luogu-judger-enable-o2
#include<iostream>
using namespace std;
char map[110][110];
int value[110][110];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == '?')
			{
				if (map[i - 1][j] == '*')
					value[i][j]++;
				if (map[i + 1][j] == '*')
					value[i][j]++;
				if (map[i][j - 1] == '*')
					value[i][j]++;
				if (map[i][j + 1] == '*')
					value[i][j]++;
				if (map[i - 1][j - 1] == '*')
					value[i][j]++;
				if (map[i - 1][j + 1] == '*')
					value[i][j]++;
				if (map[i + 1][j - 1] == '*')
					value[i][j]++;
				if (map[i + 1][j + 1] == '*')
					value[i][j]++;
			}
		}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == '*')
				cout << '*';
			else
				cout << value[i][j];
		}
		cout << endl;
	}
		
	return 0;
}