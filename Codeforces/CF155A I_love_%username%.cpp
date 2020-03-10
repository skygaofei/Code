#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n;
int minn = 0x7fffffff, maxn = -0x7fffffff;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	int temp;
	int p = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		if (i != 1)
		{
			if (temp < minn)
			{
				p++;
				minn = temp;
			}
			else if (temp > maxn)
			{
				p++;
				maxn = temp;
			}
		}
		minn = min(minn, temp);
		maxn = max(maxn, temp);
	}
	cout << p;
	return 0;
}