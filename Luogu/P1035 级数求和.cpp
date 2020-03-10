#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,n=1;
    double sn=0.0000;
    cin>>k;
    while(sn<=k)
    {sn+=1.0/n;
        n++;}
    cout<<n-1;
    return 0;
}