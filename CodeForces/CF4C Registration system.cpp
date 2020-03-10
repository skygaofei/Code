#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
map<string, long long> p;
int main() {
	ios::sync_with_stdio(false);
	string temp;
	long long n, i;
	cin >> n;
	getline(cin, temp);
	for (i = 1; i <= n; ++i) 
	{
		getline(cin, temp);
		if (p[temp] != 0)
		{
			cout << temp << p[temp] << '\n';
			++p[temp];
		}
		else
		{
			cout << "OK\n";
			p[temp] = 1;
		}
	}
	return 0;
}