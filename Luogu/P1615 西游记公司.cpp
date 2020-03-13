#include<iostream>
using namespace std;
long long h1,h2,m1,m2,s1,s2,ans,ti;
char c;
int main()
{
    cin>>h1>>c>>m1>>c>>s1>>h2>>c>>m2>>c>>s2>>ti;
    cout<<((h2-h1)*3600+(m2-m1)*60+(s2-s1))*ti;
    return 0;
}