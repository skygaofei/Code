#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a=1,b=1,i;
    cin>>n;
    for(i=1;i<n;++i)
    {
        if(b%2!=0&&a==1)
			b++;
        else if(a%2==0&&b==1)
			a++;
        else if((a+b)%2!=0)
		{
			b--;
			a++;
		}
        else if((a+b)%2==0)
		{
			b++;
			a--;
		}
    }
    cout<<a<<'/'<<b;
    return 0;
}