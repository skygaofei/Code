#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<ctime>
#include<queue>
#include<sstream>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
long long mod(long long  a, long long b, long long c) 
{
	long long ans = 1;
	while (b!=0) 
	{
		if (b % 2 == 1)
			ans = ans*a%c;
		a = a*a%c;
		b /= 2;
	}
	return ans;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int b, p, k;
	cin >> b >> p >> k;
	cout << b << '^' << p << " mod " << k << '=';
	cout << mod(b, p, k);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}