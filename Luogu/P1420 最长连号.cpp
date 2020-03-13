#include<bits/stdc++.h>
using namespace std;
int a[10000010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int k=0,sum=0;
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i-1]+1)
            k++;
        else
        {
            if(k>sum)
                sum=k;
            k=1;
        }
    }
    cout<<sum;
    return 0;
}