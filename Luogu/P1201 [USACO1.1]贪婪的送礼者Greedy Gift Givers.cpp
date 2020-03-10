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
//#include<bits/stdc++.h>
using namespace std;
string given, giver, name[15]; 
int np, i, mon[15], gift[15], wealthy, person;
int find(string s)
{
	int i = 1;
	while (s != name[i]) 
		i++;
	return i;
}
void dodo(int n) 
{
	int i;
	cin >> wealthy >> person;
	if (person== 0) 
		return;
	mon[n] = wealthy%person - wealthy;
	for (i = 1; i <= person; i++) 
	{
		cin >> given;
		gift[find(given)] += wealthy / person;
	}
}
int main() 
{
	cin >> np;
	for (i = 1; i <= np; i++)
		cin >> name[i];
	for (i = 1; i <= np; i++) 
	{
		cin >> giver;
		dodo(find(giver));
	}
	for (i = 1; i <= np; i++)
		cout << name[i] << ' ' << mon[i] + gift[i] << endl;
	return 0;
}