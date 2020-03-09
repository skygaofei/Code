// luogu-judger-enable-o2
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int step;
string num;
vector<int> a, b;
int main()
{
	int n;
	cin >> n >> num;
	for (int i = 0; i < num.length(); i++)
	{
		if (num[i] >= '0' && num[i] <= '9')
			a.push_back(num[i] - '0');
		else if (islower(num[i]))
			a.push_back(num[i] - 'a' + 10);
		else
			a.push_back(num[i] - 'A' + 10);
	}
	b = a;
	reverse(b.begin(), b.end());
	if (a == b)
	{
		cout << ("STEP=0");
		return 0;
	}
	for (int i = 1; i <= 30; i++)
	{
		int size = b.size();
		for (int j = 0; j < size; j++)
		{
			b[j] += a[j];
			if (j != size - 1)
				b[j + 1] += b[j] / n;
			else if (b[j] >= n)
				b.push_back(b[j] / n);
			b[j] = b[j] % n;
		}
		step++;
		a = b;
		reverse(b.begin(), b.end());
		if (a == b)
		{
			cout << "STEP=" << i;
			return 0;
		}
	}
	cout << "Impossible!";
	return 0;
}