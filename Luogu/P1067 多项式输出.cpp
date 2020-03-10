#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,xs;
    cin>>n;
    for(int i=n;i>=0;i--) 
	{
        cin>>xs;
        if(xs==0)
			continue;
        if(xs<0)
			cout<<'-';
        else if(i!=n)
			cout<<'+';
        if(abs(xs)!=1||i==0)
			cout<<abs(xs);
        if(i>1)
			cout<<"x^"<<i;
        else if(i==1) 
			cout<<"x";
    }
    return 0;
}
