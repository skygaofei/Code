#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	int a,b,s,max=0,i,unhappy=0;
    for (i=1;i<8;i++)
      {
        cin>>a>>b;
        s=a+b;
        if(s>8&&s>max)
		{
			max=s;
			unhappy=i; 
		} 
      }
    cout<<unhappy;
	return 0;
}
