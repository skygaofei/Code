#include<bits/stdc++.h>
using namespace std;
bool is_prime[10000005];
void prime(int n)
{
    is_prime[1]=false;
    for(int i=2;i<=n;i++)
        is_prime[i]=true;
    for(int i=2;i*i<=n;i++)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<=n;j+=i)
                is_prime[j]=false;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int x;
    prime(n);
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        if(is_prime[x])
        {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    return 0;
}