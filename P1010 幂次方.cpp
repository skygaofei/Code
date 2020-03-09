#include<bits/stdc++.h>
using namespace std;
int h(int x)
{
	if(x>4)
	{
		int i=2;
		while(pow(2,i)<=x) 
			i++;
		cout<<"2(";
		h(i-1);
		cout<<")";
		if(x!=pow(2,i-1)) 
			cout<<"+";
		h(x-pow(2,i-1));
	}
	else
	{
		if(x==0) 
			return 0;
		if(x==1) 
			cout<<"2(0)";
		if(x==2) 
			cout<<"2";
		if(x==3) 
			cout<<"2+2(0)";
		if(x==4) 
			cout<<"2(2)";
	}
}
int main()
{
	int m;
	cin>>m;
	h(m);
	return 0;
}