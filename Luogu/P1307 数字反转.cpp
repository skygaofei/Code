#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
int main()
{
    ll sum=0,a;
    cin>>a;
    while(a!=0)
    {
        sum=sum*10+a%10;
        a/=10;
    }
    cout<<sum;
	return 0;
}
