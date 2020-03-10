#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
bool flag = true, ck[27];
string s1, s2, s3;
int main()
{
	cin >> s2 >> s3 >> s1;
	int  l1 = s1.length(), l2 = s2.length();
	for (int i = 0; i<l2; i++) 
	{
		for (int j = 0; j<l2; j++) 
			if ((s2[i] == s2[j] && s3[i] != s3[j]) || (s2[i] != s2[j] && s3[i] == s3[j]))
				flag = false;
		ck[s3[i] - 'A'] = true;
	}
	for (int i = 0; i<26; i++)
	{
		if (!ck[i])
			flag = false;
	}
	if (flag) 
	{
		for (int i = 0; i < l1; i++) 
		{
			for (int j = 0; j < l2; j++) 
				if (s1[i] == s2[j]) 
				{
					cout << s3[j];
					break;
				}
		} 
	}
	else
		cout << "Failed";
}