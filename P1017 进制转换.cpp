#include<bits/stdc++.h>
using namespace std;
void jz(int a,int m)
{
	int j;
	j=a%m;
	a=a/m;
	if(j<0)
	{
		j=j-m;
		a++;
	}
	if(a!=0)
		jz(a,m);
	if(j<10)
		cout<<j;
	else
		switch(j)
		{
			case 10:
				cout<<'A';break;
			case 11:
				cout<<'B';break;
			case 12:
				cout<<'C';break;
			case 13:
				cout<<'D';break;
			case 14:
				cout<<'E';break;
			case 15:
				cout<<'F';break;
			case 16:
				cout<<'G';break;
			case 17:
				cout<<'H';break;
			case 18:
				cout<<'I';break;
			case 19:
				cout<<'J';break;
		}
	return ;
}
int main()
{
	int n,s;
	cin>>n>>s;
	cout<<n<<'=';
	jz(n,s);
	cout<<"(base"<<s<<')';
 	return 0;
}
