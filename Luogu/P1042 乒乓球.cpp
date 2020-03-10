#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1)
		s2 += s1;
	int i=0, w=0, l=0;
	while (s2[i] != 'E')
	{
		if (s2[i] == 'W')
			w++;
		if (s2[i] == 'L')
			l++;
		if ((w >= 11 || l >= 11) && abs(w - l) >= 2)
		{
			cout << w << ':' << l << endl;
			w = 0; l = 0;
		}
		i++;
	}
	i = 0;
	cout << w << ':' << l << endl;
	w = 0; l = 0;
	cout << endl;
	while (s2[i] != 'E')
	{
		if (s2[i] == 'W')
			w++;
		if (s2[i] == 'L')
			l++;
		if ((w >= 21 || l >= 21) && abs(w - l) >= 2)
		{
			cout << w << ':' << l << endl;
			w = 0; l = 0;
		}
		i++;
	}
	cout << w << ':' << l;
	return 0;
}