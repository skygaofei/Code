#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	double s, a, b;
	double t1, t2, t3, t4;
	cin >> s >> a >> b;
	double c1, c2, c;
	c1 = 0;
	c2 = s;
	do
	{
		c = (c1 + c2) / 2;
		t3 = c / b;
		t1 = t3 + (s - c) / a;
		t4 = (c - t3*a) / (a + b);
		t2 = t3 + t4 + (s - (t3 + t4)*a) / b;
		if (t1 < t2)
			c2 = c;
		else
			c1 = c;
	} while (abs(t1 - t2) > 0.0000001);
	printf("%.6lf", t1);
	return 0;
}